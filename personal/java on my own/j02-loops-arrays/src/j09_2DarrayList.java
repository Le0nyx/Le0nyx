import java.util.ArrayList;

public class j09_2DarrayList {
    public static void main(String[] args){

        ArrayList<ArrayList<String>> lists = new ArrayList<>();

        //in arraylist of the <[Wrapper class]> needed, example "Integer"
        ArrayList<String> bakery = new ArrayList<>();
        bakery.add("donuts");
        bakery.add("garlic bread");
        bakery.add("Croissant");
        bakery.add("farmers bread");
        System.out.println("List of items from bakery: \n"+bakery);
        System.out.println("I really like "+bakery.get(0));

        ArrayList<String> greenStuff = new ArrayList<>();
        greenStuff.add("pepper");
        greenStuff.add("peperoni");
        greenStuff.add("carrots");
        greenStuff.add("tomatoes");
        System.out.println("\nAll the green Stuff: \n"+greenStuff);


        ArrayList<String> drinksList = new ArrayList<>();
        drinksList.add("Coca Cola");
        drinksList.add("Fanta");
        drinksList.add("Ice Tea");
        System.out.println("\nAll the drinks: \n"+drinksList);


        lists.add(bakery);
        lists.add(greenStuff);
        lists.add(drinksList);
        System.out.println("\nHere all the things to get: \n"+lists);
        System.out.println("\nHere is the first thing in the first list: \n"+lists.get(0).get(0));
    }
}
