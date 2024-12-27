package j03_actual_abstract_robot;

public class Main {
    public static void main(String[] args) {

        Robot90 rc = new Robot90();
        rc.run_command("paallrapaarrap");
        System.out.println("--------");

        Robot45 rc2 = new Robot45();
        rc2.run_command("pall;lp ar r/P");
    }
}
