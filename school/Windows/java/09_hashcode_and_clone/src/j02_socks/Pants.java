package j02_socks;

import java.awt.*;

public class Pants extends Clothes{
    private double length;
    private String what_kind;
    private boolean isDry;
    private int dryingTime = 8;
    private static int left_drying;

    public Pants(double length, String what_kind, boolean isDry, int dryingTime) {
        this.length = length;
        this.what_kind = what_kind;
        this.isDry = isDry;
        this.dryingTime = dryingTime;
    }

    @Override
    public String toString() {
        return "Pants [lenght: " + this.length + " and what kind: " + this.what_kind + " isDry: " + this.isDry + " and drying time: " + this.dryingTime + "]";
    }


    @Override
    public void dry(){
        System.out.println("Is drying " + this);
        if(left_drying <= 0){
            this.isDry = true;
        }else{
            left_drying--;
        }
    }

    @Override
    public boolean check_if_dry() {
        return false;
    }

    @Override
    public void wash(){ isDry = false; }

    @Override
    public void setDryingTime(int x){ dryingTime = x; }

    @Override
    public void setColor(String color) {

    }

    @Override
    public Color getColor() {
        return null;
    }


}
