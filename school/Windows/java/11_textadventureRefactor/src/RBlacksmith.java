import java.util.Scanner;

public class RBlacksmith extends Room{
    Npc blacksmith = new Npc("Blacksmith Bernd",
            "A burly blacksmith greets you, his hands stained with soot and his apron worn. "
                    + "'Welcome, traveler! I've got the finest weapons and armor you'll find in these lands.'");


    public RBlacksmith(String roomName, String description) {
        super(roomName, description);
    }

    public void playScenario(Player player){
        System.out.println(blacksmith.getDescription());
        if (!player.isHasSword()) {
            System.out.println("The Blacksmith offers you a sword. Would you like to equip it? (yes/no)");
            String choice = new Scanner(System.in).nextLine().toLowerCase();
            if (choice.equals("yes")) {
                player.setHasSword(true);
                player.addItem(new Item("Sword of aegis", "The name the Blacksmith gave the sword seems fitting as its seems to be his lifelong masterpiece."));
                System.out.println("You have equipped the Sword. Your attack damage increases significantly.");
            } else {
                System.out.println("'Suit yourself,' the Blacksmith grumbles.");
            }
        } else {
            System.out.println("'You already have a sword. Don't get greedy!'");
        }

        if (!player.isHasArmor()) {
            System.out.println("The Blacksmith offers you armor. Would you like to equip it? (yes/no)");
            String choice = new Scanner(System.in).nextLine().toLowerCase();
            if (choice.equals("yes")) {
                player.setHasArmor(true);
                player.addItem(new Item("Armor of steel", "Gives quite a bit of protection for its weight. "));
                System.out.println("You have equipped the Armor. Your defending yourself now might actually have an impact.");
            } else {
                System.out.println("'Perhaps you'll change your mind later,' says the Blacksmith.");
            }
        } else {
            System.out.println("'You're already wearing armor. Any more, and you'll look like a walking fortress.'");
        }
    }
}
