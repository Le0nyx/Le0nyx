public class RWell extends Room {
    public RWell(String roomName, String description) {
        super(roomName, description);
    }

    public void playScenario(Player player){
        System.out.println("You pull on the rope to get the bucket out. You find the Talisman of Health in the well. It will double your maximum health.");
        player.addItem(new Item("Talisman of Health", "This item doubles your max HP."));
        player.setMaxhealth(player.getMaxhealth()*2);
        player.setHasTalisman(true);
    }
}
