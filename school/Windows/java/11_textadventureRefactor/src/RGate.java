public class RGate extends Room{
    public RGate(String roomName, String description) {
        super(roomName, description);
    }

    public void playScenario(Player player){
        if(player.isHasTNT()){
            System.out.println("You stand there and look at the gate you exploded with that TNT you found.");
            System.out.println("Quite the impressive damage the TNT did to it.");
        }else if(player.isKeyGate()){
            System.out.println("You stand there and look at the key for the gate you found.");
            System.out.println("You're glad the puzzle didn't have any downsides. Consequences are usually inevitable for each action. ");
        }else{
            System.out.println("You stand there and look at the gate you found.");
            System.out.println("You can't get in nor climb over it. There must be something to get to the other side.");
        }
    }
}
