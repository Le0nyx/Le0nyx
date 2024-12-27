import java.util.Scanner;

public class RTavern extends Room {
    Scanner scanner = new Scanner(System.in);

    Npc merchant = new Npc("kind Merchant",
            "A kindly old merchant greets you with a warm smile. "
                    + "'Ah, a brave soul wandering through this land. What can I do for you?'");

    public RTavern(String roomName, String description) {
        super(roomName, description);
    }

    public void playScenario(Player player){
        System.out.println("You meet a " + merchant.getName() + ".");
        System.out.println(merchant.getDescription());

        if(!HealingFlask.getHasFlask()){
            System.out.println("'You look thirsty.'\n'Need something to drink? Here I got something special for you.'");
            System.out.println("'It is a flask that you can drink from in dire situations to power yourself back up a little. It goes empty in a few gulps though.' \n'Come back to me for a refill anytime!' ");
            HealingFlask.setHasFlask(true);
            player.addItem(new Item("Healing Flask", "Healing Flask with 4 uses before it needs to get refilled in the Tavern. "));
        }else{
            System.out.println("'Have a drink of my special potions. This one refills your hp to max.' \n'By the time you come back next time I should have another ready.'");
            player.setHealth(player.getMaxhealth());
            System.out.println("'Oh, and watch out for the Catacombs. I’ve heard tales of a troll guarding a key to the Church.'");

            if(HealingFlask.getUses() < 4){
                System.out.println("Would you like to refill your Flask? (yes/no)");
                String refillChoice = scanner.nextLine().toLowerCase();
                if (refillChoice.equals("yes")) {
                    HealingFlask.refillFlask();
                }
            }else{
                System.out.println("'I see your flask is still full. Saving it for the right moment I asume?'");
            }

        }


    }
}
