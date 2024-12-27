import java.util.Scanner;

public class RBushes extends Room{
    Scanner scanner = new Scanner(System.in);

    public RBushes(String roomName, String description) {
        super(roomName, description);
    }

    public void playScenario(Player player){
        int attempts = 0;
        boolean quitBushes = false;

        while (attempts < 5 && !quitBushes) {
            System.out.println("Would you like to continue trying to go through the bushes? (yes/no)");
            String choiceBushes = scanner.nextLine().toLowerCase();

            if (!player.isHasArmor()) {
                if (choiceBushes.equals("yes")) {
                    attempts++;
                    System.out.println("You push through the thick bushes, but it hurts...");

                    // Player takes damage for each attempt
                    int damage = 5; // 5 damage per attempt
                    player.takeDamage(damage);
                    System.out.println("You take " + damage + " damage. Your health is now " + player.getHealth() + ".");
                } else if (choiceBushes.equals("no")) {
                    quitBushes = true;
                    System.out.println("You decide to stop and retreat from the bushes.");
                } else {
                    System.out.println("Invalid choice, please type 'yes' or 'no'.");
                }
            }else{
                if (choiceBushes.equals("yes")) {
                    System.out.println("Since you have armor the thorns of the bushes can not hurt you. \nYou pass through with ease. Yet some thorns seem to have pocked your face and left scratches.");
                    player.takeDamage(3);
                    System.out.println("You take " + (int)3/2 + " damage. Your health is now " + player.getHealth() + ".");
                    attempts++;
                }else if(choiceBushes.equals("no")) {
                    quitBushes = true;
                }
            }

            if (attempts == 5) {
                System.out.println("You have successfully pushed through the bushes, but you are severely hurt.");
            }
        }

        // After passing through, find the key
        if(attempts >= 5 && !player.isKeyHouse2()){
            System.out.println("You find a key here. It must unlock the cellar of that one house.");
            player.setKeyHouse2(true);
            player.addItem(new Item("Key to Cellar", "Is the key to the cellar of house 2."));
        }

    }
}
