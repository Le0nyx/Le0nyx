import javax.swing.JOptionPane;

public class DataInput {

    public static int readNumber(String message) {
        return Integer.parseInt(message);
    }

    public static void main(final String[] args) {
        String message = JOptionPane.showInputDialog("Enter here: ");
        int x = 2 + readNumber(message);
        System.out.println("2 plus the number you entered is: "+ x);
    }
}
