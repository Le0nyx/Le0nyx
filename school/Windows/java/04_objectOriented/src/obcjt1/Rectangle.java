package obcjt1;

public class Rectangle {
    private int length;
    private int width;

    public Rectangle(int length, int width) { // this is a constructor
        this.length = length; // variable gets passed from method into class variables
        this.width = width;
    }

    public int getArea(){
        return length*width;
    }

    public int getCircumference(){
        return 2* (length + width);
    }

    public void setLength(int length) { // negative length doesnt work
        if(length<0)
            length = 0;
        else
            this.length = length;
    }

    public void setWidth(int width) { // negative length doesnt work
        if(width<0)
            width = 0;
        else
            this.width = width;
    }

    public int getLength() {
        return length;
    }

    public int getWidth() {
        return width;
    }

}
