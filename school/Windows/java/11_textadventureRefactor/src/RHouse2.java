public class RHouse2 extends Room{
    public RHouse2(String roomName, String description) {
        super(roomName, description);
    }

    public void playScenario(Player player){
        System.out.println("Inside the cellar, you find TNT. This could be used to blow up the gate to the Tavern, Catacombs, or Blacksmith.");
        System.out.println("With it you blow open the Gate to the Tavern, Blacksmith and the Catacombs. ");
        player.setHasTNT(true);
        player.addItem(new Item("Rests of exploded TNT", "You still have some TNT leftover from exploding the gate. It might come in handy."));
    }
}
