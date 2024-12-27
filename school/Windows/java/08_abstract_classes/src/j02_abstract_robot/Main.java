package j02_abstract_robot;

public class Main {
    public static void main(String[] args) {

        RemoteControl rc = new RemoteControl();
        rc.run_command("paallrapaarrap");
        System.out.println("--------");

        RemoteControl rc2 = new RemoteControl();
        rc2.run_command("pal;lp ar r/P");
    }
}
