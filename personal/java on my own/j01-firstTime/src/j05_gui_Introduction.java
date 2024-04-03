import javax.swing.JOptionPane;
public class j05_gui_Introduction {
    public static void main(String[] args){
        String name = JOptionPane.showInputDialog("Please enter your name");
        JOptionPane.showMessageDialog(null, "Hello "+name);


        System.out.println("First window closed");
        int age = Integer.parseInt(JOptionPane.showInputDialog("Please enter your age: "));
        //parseInt converts it to an integer (wrapper)
        //needs to enter integer since no exceptions yet
        JOptionPane.showMessageDialog(null, age);


        System.out.println("Second window closed");
        double height = Double.parseDouble(JOptionPane.showInputDialog("Please enter your height: "));
        JOptionPane.showMessageDialog(null, "You are "+height+"m");
    }
}