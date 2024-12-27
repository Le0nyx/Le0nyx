import java.util.Random;
import java.util.Scanner;

public class CombatTroll {
    public static void fightTroll(Player player) {
        int trollHealth = 80;
        int BaseTrollAttack = 15;

        System.out.println("A troll approaches! It roars and prepares to attack.");

        while (trollHealth > 0 && player.getHealth() > 0) {
            int trollAttack = (int)((double)BaseTrollAttack * getRandomMultiplier());
            System.out.println("Your health: " + player.getHealth() + " | Troll's health: " + trollHealth);
            System.out.println("What will you do? (Attack/Defend/Heal)");

            String action = new Scanner(System.in).nextLine().toLowerCase();

            switch (action) {
                case "attack":
                    int damage = player.getattackDamage();
                    trollHealth -= damage;
                    System.out.println("You attack the troll and deal " + damage + " damage.");
                    break;
                case "defend":
                    System.out.println("You brace yourself for the next attack.");
                    player.setHealth(player.getHealth() - trollAttack/2);
                    break;
                case "heal":

                    HealingFlask.drinkFromFlask(player);

                    break;
                default:
                    System.out.println("Invalid action.");
                    continue;
            }

            if (trollHealth > 0) {
                player.takeDamage(trollAttack);
                System.out.println("The troll attacks you and deals " + trollAttack + " damage.");
            }
        }

        if (player.getHealth() <= 0) {
            System.out.println("You have been defeated by the troll. Game over.");
            player.setStillAlive(false);
            System.exit(0); // Game over
        } else {
            System.out.println("The troll is defeated!");
            player.setTrollDefeated(true);
        }
    }//end of troll fight

    public static double getRandomMultiplier() {
        Random random = new Random();
        return 0.5 + random.nextDouble(); // between 0.5 and 1.5
    }
}
