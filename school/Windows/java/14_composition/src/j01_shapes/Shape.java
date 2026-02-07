package j01_shapes;
import java.util.ArrayList;

public abstract class Shape {
    private ArrayList<Shape> list;

    public Shape() {
        list = new ArrayList<Shape>();
    }

    public void addShape(Shape s) {
        list.add(s);
    }

    public void display() {
        for (Shape s : list) {
            s.display();
        }
    }
}
