package j04_dollarToEuroInterfaces;

public class Euro extends Number implements Waehrung, Comparable {
    private int euros;
    private int cent;


    public Euro(int euros, int cent) {
        this.euros = euros;
        if(cent < 0 || cent > 99){
            this.cent = 0;
        }else {
            this.cent = cent;
        }
    }
    public Euro(){
        this(0, 0);
    }

    private long getTotalCents(){
        if(this.euros > 0 && this.cent > 0){
            return (long) this.euros * 100 + this.cent;
        }else if(this.euros < 0){
            return (long) this.euros * 100 - this.cent;
        }
        return 0;
    }

    @Override
    public String symbol(){
        return "€";
    }

    @Override
    public Waehrung mult(double f){
        return new Euro((int) ((double) ((getTotalCents()*f) /100)), (int) (getTotalCents()*f)%100);
    }





    @Override
    public int intValue() {
        return this.euros;
    }

    @Override
    public long longValue() {
        return (long) this.euros;
    }

    @Override
    public float floatValue() {
        if(this.euros > 0){
            return (float) this.euros + (float) this.cent/100;
        }else{
            return (float) this.euros - (float) this.cent/100;
        }
    }

    @Override
    public double doubleValue() {
        if(this.euros > 0){
            return (double) this.euros + (double) this.cent/100;
        }else{
            return (double) this.euros - (double) this.cent/100;
        }
    }

    @Override
    public int compareTo(Object o) {
        if(o.getClass().getSimpleName().equals(this.getClass().getSimpleName())){
            return 1;
        }else{
            return -1;
        }
    }

    @Override
    public String toString(){
        return "Euro: " + euros + "," + cent + symbol();
    }

}
