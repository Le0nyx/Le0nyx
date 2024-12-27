public class HealingFlask extends Item{
    private static int uses = 4;
    private static boolean hasFlask = false;

    public HealingFlask(String name, String description) {
        super(name, description);
    }

    public static void drinkFromFlask(Player playername){
        if(hasFlask){
            if(uses>0){
                playername.setHealth(playername.getHealth()+25);
                uses--;
            }else{
                System.out.println("You don't have enough left in Flask to heal");
            }
        }else{
            System.out.println("You don't have a Flask to heal. ");
        }
    }

    public static void refillFlask(){
        uses = 4;
    }

    public static boolean getHasFlask() {
        return hasFlask;
    }

    public static void setHasFlask(boolean hasFlask) {
        HealingFlask.hasFlask = hasFlask;
    }

    public static int getUses() {
        return uses;
    }
}
