package j01_VererbungMenschJob;

public class Bueroangesteller extends Mensch {
    private double gehalt;
    private String zustaendigkeits_bereich;

    public Bueroangesteller(String name, int age, double gehalt, String zustaendigkeits_bereich) {
        super(name, age);
        this.gehalt = gehalt;
        this.zustaendigkeits_bereich = zustaendigkeits_bereich;
    }

    public void earnedMoney(double cash) {
        this.gehalt += cash;
    }



    public double getGehalt() {
        return gehalt;
    }

    public String getZustaendigkeits_bereich() {
        return zustaendigkeits_bereich;
    }
}
