package j03_dollarToEuro;

public class Dollar extends Number {
    private int dollars;
    private int cent;


    public Dollar(int dollars, int cent) {
        this.dollars = dollars;
        if(cent < 0 || cent > 99){
            this.cent = 0;
        }else {
            this.cent = cent;
        }
    }
    public Dollar(){
        this(0, 0);
    }

    public long getTotalCents(){
        return (long) this.dollars * 100 + this.cent;
    }



    @Override
    public int intValue() {
        return this.dollars;
    }

    @Override
    public long longValue() {
        return (long) this.dollars;
    }

    @Override
    public float floatValue() {
        if(this.dollars>0){
            return (float) this.dollars + (float) this.cent/100;
        }else{
            return (float) this.dollars - (float) this.cent/100;
        }
    }

    @Override
    public double doubleValue() {
        if(this.dollars>0){
            return (double) this.dollars + (double) this.cent/100;
        }else{
            return (double) this.dollars - (double) this.cent/100;
        }
    }
}
