package j02_abstract_robot;

public class Robot {
    private double x;
    private double y;
    private int facing;

    public Robot(double x, double y, int facing) {
        this.x = x;
        this.y = y;
        this.facing = facing;
    }
    public Robot(){ this(0, 0, 0); }

    public String getPos(){
        System.out.println(" " + x + "; " +y + "; " + facing);
        return " " + x + " ; " + y;
    }

    public void advance(){
        if(facing == 0){ y++; }
        else if(facing == 90){ x++; }
        else if(facing == 180){ y--; }
        else if(facing == 270){ x--; }
    }

    public void turnLeft(){
        if(facing == 0){
            facing = 270;
        }else{
            facing -= 90;
        }
    }

    public void turnRight(){
        if(facing == 270){
            facing = 0;
        }else{
            facing += 90;
        }
    }

}
