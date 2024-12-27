public class RHouse1 extends Room{
    Npc villager = new Npc("Weary Villager",
            "A frail villager sits by the fireplace, their eyes sunken with exhaustion. "
                    + "'So, you made it this far,' he says with a weak smile.");


    public RHouse1(String roomName, String description) {
        super(roomName, description);
    }

    public void playScenario(Player player){
        System.out.println("You meet " + villager.getName() + ".");
        System.out.println(villager.getDescription());

        // Dialog with NPC
        System.out.println("The villager continues: ");
        System.out.println("'The world has gone dark since the dragon took over the Church. The Merchant in the Tavern might have something to help you.'");
        System.out.println("'Beware of the Catacombs. They house more than just skeletons. I’ve heard of a troll that guards something important.'");
        System.out.println("'If you ever make it to the Church, remember this: the dragon is not easily defeated without courage and strength.'");

        System.out.println("You thank the villager for their guidance and leave the house.");

    }

}
