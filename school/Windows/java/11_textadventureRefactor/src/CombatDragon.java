import java.util.Random;
import java.util.Scanner;

public class CombatDragon {
    public static void fightDragon(Player player) {
        int dragonHealth = 200;
        int BaseDragonAttack = 25;
        boolean tnt_chance = player.isHasTNT();

        System.out.println("You enter the Church and see a massive dragon!");

        while (dragonHealth > 0 && player.getHealth() > 0) {
            int dragonAttack = (int)((double)BaseDragonAttack * getRandomMultiplier());
            System.out.println("Your health: " + player.getHealth() + " | Dragon's health: " + dragonHealth);
            System.out.println("What will you do? (Attack/Defend/heal)");

            String action = new Scanner(System.in).nextLine().toLowerCase();

            switch (action) {
                case "attack":
                    int damage = player.getattackDamage();
                    if(tnt_chance){
                        System.out.println("You remembered the rest of TNT in your inventory and throw some at the dragon. \nAs he charges a breath attack he ignites the TNT in his mouth.");
                        tnt_chance = false;
                        System.out.println("You dealt "+ damage*2 + " of damage to the dragon with the TNT leftover. ");
                        dragonHealth -= damage*2;
                    }else{
                        System.out.println("You strike the dragon and deal " + damage + " damage.");
                        dragonHealth -= damage;
                    }
                    break;
                case "defend":
                    System.out.println("You brace for the dragon's fiery attack.");
                    player.setHealth(player.getHealth() - dragonAttack/2);
                    break;
                case "heal":

                    HealingFlask.drinkFromFlask(player);

                    break;
                default:
                    System.out.println("Invalid action.");
                    continue;
            }

            if (dragonHealth > 0) {
                // Dragon attacks
                player.takeDamage(dragonAttack);
                System.out.println("The dragon breathes fire and deals " + dragonAttack + " damage.");
            }
        }

        if (player.getHealth() <= 0) {
            System.out.println("You have been defeated by the dragon. Game over.");
            player.setStillAlive(false);
            System.exit(0); // Game over
        } else {
            System.out.println("\nThe dragon is slain! You have completed your journey.");
        }
    }// end of combat method

    public static double getRandomMultiplier() {
        Random random = new Random();
        return 0.5 + random.nextDouble(); // between 0.5 and 1.5
    }
}
