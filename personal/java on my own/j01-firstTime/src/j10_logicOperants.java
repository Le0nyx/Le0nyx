public class j10_logicOperants {
    public static void main(String[] args){
        // logical operands to use && || !

        double temperature = 22.5;

        if((temperature >= 20 && temperature <= 25) || temperature == 0){
            System.out.println("Its nice and cozy");
        }else if(!(temperature>20)){
            System.out.println("Temprature is cold?");
        }else{
            System.out.println("ello");
        }
    }
}
