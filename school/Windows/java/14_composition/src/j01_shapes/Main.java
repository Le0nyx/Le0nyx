package j01_shapes;

public class Main {
    public static void main(String[] args) {
        // Create individual shapes
        Circle circle = new Circle();
        Rectangle rectangle = new Rectangle();
        Triangle triangle = new Triangle();

        // Create a composed shape
        ComposedShape composedShape = new ComposedShape();

        // Add shapes to the composed shape
        composedShape.addShape(circle);
        composedShape.addShape(rectangle);
        composedShape.addShape(triangle);

        // Display all shapes
        System.out.println("Displaying individual shapes:");
        circle.display();
        rectangle.display();
        triangle.display();

        System.out.println("\nDisplaying composed shape:");
        composedShape.display();
    }
}
