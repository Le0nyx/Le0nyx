package j02_socks;
import java.awt.*;

public class Sock extends Clothes{
    private Color color;
    private boolean isDry;
    private int dryingTime = 8;
    private static int left_drying;

    Sock(String color, boolean isDry) {
        this.color = Sock.stringToColor(color);
        this.isDry = isDry;
    }
    Sock(String color) {
        this(color, true);
    }
    Sock(){
        this("", true);
    }


    @Override
    public String toString() {
        return "Sock [color=" + color + ", isDry=" + isDry + ", dryingTime=" + dryingTime + "]";
    }


    @Override
    public boolean check_if_dry(){
        return this.isDry;
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
    public void wash(){
        this.isDry = false;
        left_drying = dryingTime;

        //lower the saturation on the colors
        float[] hsb = Color.RGBtoHSB(color.getRed(), color.getGreen(), color.getBlue(), null);
        color =  Color.getHSBColor(hsb[0], hsb[1] * 0.8f, hsb[2]);
    }

    @Override
    public Color getColor() {
        return color;
    }
    @Override
    public void setColor(String color) {
        this.color = Sock.stringToColor(color);
    }


    public static Color stringToColor(String s) {
        if (s == null || s.isEmpty()) { return Color.BLACK; }
        s = s.trim().toLowerCase();

        switch (s) {
            case "black": return Color.BLACK;
            case "white": return Color.WHITE;
            case "red": return Color.RED;
            case "green": return Color.GREEN;
            case "blue": return Color.BLUE;
            case "yellow": return Color.YELLOW;
            case "cyan": return Color.CYAN;
            case "magenta": return Color.MAGENTA;
            case "gray": return Color.GRAY;
            case "darkgray": return Color.DARK_GRAY;
            case "lightgray": return Color.LIGHT_GRAY;
            case "pink": return Color.PINK;
            case "orange": return Color.ORANGE;
            default: return Color.BLACK;
        }
    }

    @Override
    public void setDryingTime(int x){ dryingTime = x; }


}
