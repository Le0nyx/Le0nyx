package j01_VererbungMenschJob;

public class Main {
    public static void main(String[] args) {

        Sportler max = new Sportler("Max", 25, 1.80, 76.54);
        max.years_aged(3);
        max.gainWeight(-3);
        System.out.println(max.getName()+ ", "+ max.getAge()+ ", "+ max.getWeight());

        Bueroangesteller kevin = new Bueroangesteller("Kevin", 67, 2300, "Software-development");

        kevin.earnedMoney(4321.50);
        System.out.println(kevin.getZustaendigkeits_bereich());
        System.out.println(kevin.getName() + ", "+ kevin.getGehalt());

        Stuermer moritz = new Stuermer("Moritz", 19, 1.65, 70.20, 43, 6, 365, 143);
        moritz.years_aged(3);
        moritz.gainWeight(-3);

        System.out.println(moritz.getAge() + ", "+ moritz.getgoals());
    }
}