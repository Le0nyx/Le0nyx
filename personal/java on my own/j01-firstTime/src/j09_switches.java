public class j09_switches {
    public static void main(String[] args){
        String day = "Friday";

        switch (day) {
            case "Monday":
                System.out.println("It is monday");
                break;
            case "Tuesday":
                System.out.println("it might be tuesday");
                break;
            case "Wednesday":
                System.out.println("It should be wednesday");
                break;
            case "Thursday":
                System.out.println("could be thursday");
                break;
            case "Friday":
                System.out.println("Finally its Friday");
                break;
            case "Saturday":
                System.out.println("Saturday it is");
                break;
            case "Sunday":
                System.out.println("It is sunday");
                break;
            default:
                System.out.println("Not within range");
                // no break needed here as it is last case
        }
    }
}
