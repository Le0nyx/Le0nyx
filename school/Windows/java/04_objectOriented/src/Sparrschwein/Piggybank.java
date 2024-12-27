package Sparrschwein;

public class Piggybank {
    private int cent1;
    private int cent10;
    private int cent50;
    private int euro1;

    private int max_pieces;
    private boolean is_broken;


    public void init_piggybank(int max_pieces) {
        this.cent1 = 0;
        this.cent10 = 0;
        this.cent50 = 0;
        this.euro1 = 0;
        this.max_pieces = max_pieces;
        this.is_broken = false;
    }

    public boolean is_broken() {
        return is_broken;
    }
    public boolean is_full() {
        return this.cent1 + this.cent10 + this.cent50 + this.euro1 == this.max_pieces;
    }
    public boolean is_empty() {
        return cent1 == 0 && cent10 == 0 && cent50 == 0 && euro1 == 0;
    }
    public void setBankStatus(boolean is_broken){
        this.is_broken = is_broken;
    }


    public int add1Cents(int count) {
        if (is_broken) {
            System.out.println("Cannot add coins to a broken piggy bank.");
            return count; // Return all coins if the piggy bank is broken
        }

        int spaceLeft = max_pieces - (cent1 + cent10 + cent50 + euro1); // Available space in the piggy bank

        if (count <= spaceLeft) {
            // All coins fit in the piggy bank
            cent1 += count;
            return 0; // Return 0 because all coins were added
        } else {
            // Piggy bank is full or overflows
            cent1 += spaceLeft; // Fill up the remaining space with as many coins as possible
            return count - spaceLeft; // Return the number of coins that couldn't be added
        }
    }

    public int breakInto(){
        if(!this.is_broken) {
            this.is_broken = true;
            return (this.cent1 + this.cent10 + this.cent50) + (this.euro1 * 100); //returns total value of all in cents
        }
        return -1;
    }
    
    
    // ----------------------------------------

    // Method to add 10-Cent coins
    public int add10Cents(int count) {
        if (is_broken) return count;

        int totalCoins = cent1 + cent10 + cent50 + euro1;
        int spaceLeft = max_pieces - totalCoins;

        if (count <= spaceLeft) {
            cent10 += count;
            return 0;
        } else {
            cent10 += spaceLeft;
            return count - spaceLeft;
        }
    }

    // Method to add 50-Cent coins
    public int add50Cents(int count) {
        if (is_broken) return count;

        int totalCoins = cent1 + cent10 + cent50 + euro1;
        int spaceLeft = max_pieces - totalCoins;

        if (count <= spaceLeft) {
            cent50 += count;
            return 0;
        } else {
            cent50 += spaceLeft;
            return count - spaceLeft;
        }
    }

    // Method to add 1-Euro coins
    public int add1Euros(int count) {
        if (is_broken) return count;

        int totalCoins = cent1 + cent10 + cent50 + euro1;
        int spaceLeft = max_pieces - totalCoins;

        if (count <= spaceLeft) {
            euro1 += count;
            return 0;
        } else {
            euro1 += spaceLeft;
            return count - spaceLeft;
        }
    }

    // Method to add coins (four different types at once)
    public boolean addCoins(int oneCentCount, int tenCentCount, int fiftyCentCount, int oneEuroCount) {
        if (is_broken) return false; // Can't add to broken piggy bank

        // Try to add each type of coin
        int overflow1Cents = add1Cents(oneCentCount);
        int overflow10Cents = add10Cents(tenCentCount);
        int overflow50Cents = add50Cents(fiftyCentCount);
        int overflow1Euros = add1Euros(oneEuroCount);

        // If there's no overflow for any coin type, return true
        return (overflow1Cents == 0 && overflow10Cents == 0 && overflow50Cents == 0 && overflow1Euros == 0);
    }

    // Overloaded addCoins method to break another piggy bank and transfer coins
    public boolean addCoins(Piggybank otherPiggyBank) {
        if (this == otherPiggyBank || this.is_broken || otherPiggyBank.is_broken) {
            return false; // Can't transfer from/to the same or broken piggy banks
        }

        // Break the other piggy bank and retrieve coins
        int othercent1 = otherPiggyBank.cent1;
        int othercent10 = otherPiggyBank.cent10;
        int othercent50 = otherPiggyBank.cent50;
        int othereuro1 = otherPiggyBank.euro1;

        // Reset the other piggy bank
        otherPiggyBank.cent1 = 0;
        otherPiggyBank.cent10 = 0;
        otherPiggyBank.cent50 = 0;
        otherPiggyBank.euro1 = 0;
        otherPiggyBank.is_broken = true;

        // Try to add all the retrieved coins to this piggy bank
        return addCoins(othercent1, othercent10, othercent50, othereuro1);
    }

    // Method to compare the weight of two piggy banks
    public boolean isLighterThan(Piggybank otherPiggyBank) {
        int thisWeight = this.cent1 * 2 + this.cent10 * 4 + this.cent50 * 7 + this.euro1 * 7;
        int otherWeight = otherPiggyBank.cent1 * 2 + otherPiggyBank.cent10 * 4 + otherPiggyBank.cent50 * 7 + otherPiggyBank.euro1 * 7;

        return thisWeight < otherWeight;
    }


}
