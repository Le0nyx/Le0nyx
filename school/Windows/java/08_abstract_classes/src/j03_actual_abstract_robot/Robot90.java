package j03_actual_abstract_robot;

public class Robot90 extends RemoteControl {
    private double x = 0;
    private double y = 0;
    private int facing = 0;

    @Override
    public String getPos(){
        System.out.println(" " + x + "; " +y + "; " + facing);
        return " " + x + " ; " + y;
    }

    @Override
    public void advance(){
        if(facing == 0){ y++; }
        else if(facing == 90){ x++; }
        else if(facing == 180){ y--; }
        else if(facing == 270){ x--; }
    }

    @Override
    public void turnLeft(){
        if(facing == 0){ facing = 270; }
        else{ facing -= 90; }
    }

    @Override
    public void turnRight(){
        if(facing == 270){ facing = 0; }
        else{ facing += 90; }
    }

}
