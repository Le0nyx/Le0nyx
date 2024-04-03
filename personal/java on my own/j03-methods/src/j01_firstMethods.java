public class j01_firstMethods {
    public static void main(String[] args){
        //method is like function in C
        String food = "pizza";
        hello(food);

        int x = 5;
        int y = -3;
        System.out.println("Number added of "+ x +" and "+ y +" is equal to "+ add(x, y));

    }

    static void hello(String sm1){
        System.out.println("Chapter22 in vid");
        System.out.println("I see you like "+sm1);
    }

    static int add(int a, int b){
        return a+b;
    }
}
