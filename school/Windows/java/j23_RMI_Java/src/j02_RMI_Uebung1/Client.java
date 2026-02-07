package j02_RMI_Uebung1;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String host = "localhost";

        System.out.println("Choose option:");
        System.out.println("1) Quadrat.quadrat(long)");
        System.out.println("2) Task.compute(a, b, op) (+ - * /)");
        System.out.print("choice (1 or 2): ");
        String choice = sc.nextLine().trim();

        try {
            Registry reg = LocateRegistry.getRegistry(host, 1099);

            if ("1".equals(choice)) {
                System.out.print("Enter integer number: ");
                long zahl;
                try {
                    zahl = Long.parseLong(sc.nextLine().trim());
                } catch (NumberFormatException e) {
                    System.out.println("number error");
                    return;
                }

                Quadrat q = (Quadrat) reg.lookup("Quadrat");
                long result = q.quadrat(zahl);
                System.out.println("square of " + zahl + " = " + result);

            } else {
                System.out.print("Enter operator (+ - * /): ");
                String opStr = sc.nextLine().trim();
                char op = opStr.charAt(0);

                System.out.print("Enter first number: ");
                double a;
                try {
                    a = Double.parseDouble(sc.nextLine().trim());
                } catch (NumberFormatException e) {
                    System.out.println("number error");
                    return;
                }

                System.out.print("Enter second number: ");
                double b;
                try {
                    b = Double.parseDouble(sc.nextLine().trim());
                } catch (NumberFormatException e) {
                    System.out.println("number error");
                    return;
                }

                Task t = (Task) reg.lookup("Task");
                try {
                    double result = t.execute(a, b, op);
                    System.out.println(a + " " + op + " " + b + " = " + result);
                } catch (Exception e) {
                    System.out.println("error " + e.getMessage());
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            sc.close();
        }
    }
}
