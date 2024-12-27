package obcjt1_withoutConstructor.obcjt1;

public class Rectangle {
    int length;
    int width;


    int getArea(){
        return length*width;
    }

    int getCircumference(){
        return 2* (length + width);
    }
}
