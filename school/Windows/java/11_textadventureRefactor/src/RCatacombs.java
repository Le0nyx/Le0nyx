import java.util.Scanner;

public class RCatacombs extends Room{
    Scanner scanner = new Scanner(System.in);

    public RCatacombs(String roomName, String description) {
        super(roomName, description);
    }


    public void playScenario(Player player){
        System.out.println("You are about to fight a troll. Are you sure you are ready? (yes/no)");
        String response = scanner.nextLine().toLowerCase();

        if(response.equals("yes")){

            CombatTroll.fightTroll(player);
            player.setTrollDefeated(true);

            player.addItem(new Item("Key to Curch", "Key to the curch obtained by slaying an Troll that had it in his possession."));

            System.out.println("Congratulations! You defeated a troll. He was hiding a key. It seems to fit the lock of the curch.\nAre you ready knight? ");
        }else{
            System.out.println("You back away again onto the street");
        }
    }
}
