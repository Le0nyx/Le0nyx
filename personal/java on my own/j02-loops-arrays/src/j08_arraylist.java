import java.util.ArrayList;
public class j08_arraylist {
    public static void main(String[] args){
        // an arraylist is a resizable array even while running (only stores reference types)
        ArrayList<String> food = new ArrayList<String>();

        food.add("Hamburger");
        food.add("Pizza");
        food.add("Burger");

        food.set(1, "hotdog"); //overwrites
        food.remove(0); //removes refrence to first

        for(int i = 0;i < food.size();i++){
            System.out.println(food.get(i));
        }
        food.clear(); //clears all refrences so it wont print anything
        for(int i = 0;i < food.size();i++){
            System.out.println(food.get(i));
        }
    }
}
