package j01_VererbungMenschJob;

public class Torwart extends Fussballer {
    private int goals_saved;
    private int matches_won;

    public Torwart(String name, int age, double size_meters, double how_fat, int goals, int seasons_played, int goals_saved, int matches_won) {
        super(name, age, size_meters, how_fat, goals, seasons_played);
        this.goals_saved = goals_saved;
        this.matches_won = matches_won;
    }

    public void savedGoals(int goals) {
        if(goals > 0) {
            this.goals_saved += goals;
        }
    }

    public void winMatch(){
        this.matches_won++;
    }



    public int getGoalsSaved() {
        return goals_saved;
    }
    public int getMatchesWon() {
        return matches_won;
    }
}
