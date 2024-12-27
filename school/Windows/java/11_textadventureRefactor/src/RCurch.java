import java.util.Scanner;

public class RCurch extends Room{
    Scanner scanner = new Scanner(System.in);

    public RCurch(String roomName, String description) {
        super(roomName, description);
    }


    public void playScenario(Player player){
        System.out.println("You are about to fight a big dragon. Are you sure you are ready? (yes/no)");
        String response = scanner.nextLine().toLowerCase();

        if(response.equals("yes")){

            CombatDragon.fightDragon(player);

            player.addItem(new Item("Dragon Scales", "Scales obtained by an obsidian coloured dragon that you have slain. "));

            System.out.println("Congratulations, brave knight! You have completed the game.");
            System.exit(0);
        }else{
            System.out.println("You back away again onto the street");
        }
    }
}
