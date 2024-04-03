public class j08_ifStatements {
    public static void main(String[] args){
        int a = 90;

        if(a >= 80){
            System.out.println("You are pretty old");
        }
        if(a < 18){
            System.out.println("You are still underage");
        }else if(a == 18){
            System.out.println("You are 18!");
        }else{
            System.out.println("You are over 18");
        }
    }
}