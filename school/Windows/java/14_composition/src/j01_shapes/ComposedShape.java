package j01_shapes;
import java.util.ArrayList;

public class ComposedShape extends Shape {
    private ArrayList<Shape> list;

    public void display(){
        System.out.println("ComposedShape");

        for(Shape s : list){
            s.display();
        }
    }

    public ComposedShape() {
        list = new ArrayList<Shape>();
    }

    public void addShape(Shape s) {
        list.add(s);
    }
}
