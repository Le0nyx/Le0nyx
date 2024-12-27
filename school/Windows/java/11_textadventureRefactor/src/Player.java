import java.util.ArrayList;

public class Player {
    private String playerName;
    private int maxhealth = 100;
    private int health = maxhealth;
    private int attackDamage = 5;
    private Room currentRoom;


    private boolean hasArmor = false;
    private boolean hasSword = false;
    private boolean KeyHouse2 = false;
    private boolean keyGate = false;
    private boolean hasTNT = false;
    private boolean solvedPuzzle = false;
    private boolean trollDefeated = false;
    private boolean stillAlive = true;
    private boolean hasTalisman = false;

    private ArrayList<Item> inventory = new ArrayList<>();

    public Player(String playerName, Room currentRoom) {
        this.playerName = playerName;
        this.currentRoom = currentRoom;
    }

    public boolean isHasTalisman() {
        return hasTalisman;
    }

    public void setHasTalisman(boolean hasTalisman) {
        this.hasTalisman = hasTalisman;
    }

    public void addItem(Item item) {
        inventory.add(item);
    }

    public void printInventory() {
        System.out.println("Items in the inventory: \n");
        if(HealingFlask.getHasFlask()){
            System.out.println(" - Flask uses left: " + HealingFlask.getUses() + "/4");
        }
        for (Item item : inventory) {
            System.out.println(" - " + item.getName() + ": " + item.getDescription());
        }
    }

    public int getattackDamage() {
        if (hasSword) {
            return attackDamage * 5;
        } else {
            System.out.println("A sword for more damage would be really helpful right now.");
            return attackDamage;
        }
    }

    public void takeDamage(int damage) {
        if(hasArmor) {
            health -= damage/2;
        }else{
            System.out.println("Some armor would really help instead of blocking with hands.");
            health -= damage;
        }
    }

    public void setHealth(int health) {
        if (health > maxhealth) {
            this.health = maxhealth;
        } else if (health < 0) {
            this.health = 0;
        } else {
            this.health = health;
        }
    }

    public void setStillAlive(boolean stillAlive) {
        this.stillAlive = stillAlive;
    }

    public boolean getStillAlive() {
        return stillAlive;
    }

    public String getPlayerName() {
        return playerName;
    }

    public boolean isTrollDefeated() {
        return trollDefeated;
    }

    public void setTrollDefeated(boolean trollDefeated) {
        this.trollDefeated = trollDefeated;
    }

    public boolean isSolvedPuzzle() {
        return solvedPuzzle;
    }

    public void setSolvedPuzzle(boolean solvedPuzzle) {
        this.solvedPuzzle = solvedPuzzle;
    }

    public boolean isHasTNT() {
        return hasTNT;
    }

    public void setHasTNT(boolean hasTNT) {
        this.hasTNT = hasTNT;
    }

    public boolean isKeyGate() {
        return keyGate;
    }

    public void setKeyGate(boolean keyGate) {
        this.keyGate = keyGate;
    }

    public boolean isKeyHouse2() {
        return KeyHouse2;
    }

    public void setKeyHouse2(boolean keyHouse2) {
        KeyHouse2 = keyHouse2;
    }

    public boolean isHasSword() {
        return hasSword;
    }

    public void setHasSword(boolean hasSword) {
        this.hasSword = hasSword;
    }

    public boolean isHasArmor() {
        return hasArmor;
    }

    public void setHasArmor(boolean hasArmor) {
        this.hasArmor = hasArmor;
    }

    public Room getCurrentRoom() {
        return currentRoom;
    }

    public void setCurrentRoom(Room currentRoom) {
        this.currentRoom = currentRoom;
    }

    public int getHealth() {
        return health;
    }

    public int getMaxhealth() {
        return maxhealth;
    }

    public void setMaxhealth(int maxhealth) {
        this.maxhealth = maxhealth;
    }
}
