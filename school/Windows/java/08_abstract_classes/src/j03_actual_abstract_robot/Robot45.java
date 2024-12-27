package j03_actual_abstract_robot;

public class Robot45 extends RemoteControl {
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
        else if(facing == 45){ x = x + Math.sqrt(2); y = y + Math.sqrt(2); }
        else if(facing == 90){ x++; }
        else if(facing == 135){ x = x + Math.sqrt(2); y = y - Math.sqrt(2); }
        else if(facing == 180){ y--; }
        else if(facing == 225){ x = x - Math.sqrt(2); y = y - Math.sqrt(2); }
        else if(facing == 270){ x--; }
        else if(facing == 315){ y = y + Math.sqrt(2); x = x - Math.sqrt(2); }
    }

    @Override
    public void turnLeft(){
        if(facing == 0){ facing = 315; }
        else{ facing -= 45; }
    }

    @Override
    public void turnRight(){
        if(facing == 315){ facing = 0; }
        else{ facing += 45; }
    }

}
