import java.util.ArrayList;

public class j10_forEachLoop {
    public static void main(String[] args){

        ArrayList<String> animals = new ArrayList<>();
        animals.add("dog");
        animals.add("cat");
        animals.add("rat");
        animals.add("bird");

        for(String i: animals){ //iterates through the elements
            //for([Datatype] [Index as example i] : [arraylist or collection] )   : = represents the word in
            System.out.print(i+", ");
        }
    }
}
