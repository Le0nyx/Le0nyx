package j02_socks;

import java.awt.*;

public interface Washable {

    public void wash();
    public void setDryingTime(int x);
    public void setColor(String color);
    public Color getColor();
    public void dry();
    public boolean check_if_dry();



}
