import java.util.Scanner;

public class RHouse3 extends Room {
    Scanner scanner = new Scanner(System.in);

    public RHouse3(String roomName, String description) {
        super(roomName, description);
    }


    public void playScenario(Player player){
        System.out.println("You encounter a puzzle inscribed on the wall. Solve it to retrieve the key for the gate.");
        System.out.println("The puzzle: Two men are standing outside an arena. One man goes in and faces his fear. The other runs home. What does the man going in have the other man doesn't have? \n");
        String magicWord = scanner.nextLine();
        if (magicWord.equalsIgnoreCase("Courage")) {
            System.out.println("You have solved the puzzle!");
            player.setSolvedPuzzle(true);
            player.setKeyGate(true);
            player.addItem(new Item("Key for Gate", "You find the key for the Gate to pass through. Though some explosions would still be fun."));
            System.out.println("You find a key to the Gate. You can now access the the Tavern, Blacksmith and Catacombs.");
        } else {
            System.out.println("The magic word is incorrect.");
            System.out.println("Come back to my house when you figured out the puzzle traveler!");
        }

    }
}
