package j01_VererbungMenschJob;

public class Fussballer extends Sportler {
    private int goals;
    private int seasons_played;

    public Fussballer(String name, int age, double size_meters, double how_fat, int goals, int seasons_played) {
        super(name, age, size_meters, how_fat);
        this.goals = goals;
        this.seasons_played = seasons_played;
    }

    public void madeGoal() {
        this.goals++;
    }

    public void setseasons_played(int seasons_played) {
        if(seasons_played >= 0){
            this.seasons_played = seasons_played;
        }
    }




    public int getseasons_played() {
        return this.seasons_played;
    }
    public int getgoals() {
        return this.goals;
    }
}
