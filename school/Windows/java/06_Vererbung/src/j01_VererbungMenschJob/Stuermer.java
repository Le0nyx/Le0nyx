package j01_VererbungMenschJob;

public class Stuermer extends Fussballer {
    private double playtime;
    private int minutes_on_bench;


    public Stuermer(String name, int age, double size_meters, double how_fat, int goals, int seasons_played, double playtime, int minutes_on_bench) {
        super(name, age, size_meters, how_fat, goals, seasons_played);
        this.playtime = playtime;
        this.minutes_on_bench = minutes_on_bench;
    }

    public void gainPlaytime(double playtime) {
        if(playtime > 0){
            this.playtime += playtime;
        }
    }

    public void gainMinutes_on_bench(int minutes_on_bench) {
        if(minutes_on_bench > 0){
            this.minutes_on_bench += minutes_on_bench;
        }
    }



    public double getPlaytime() {
        return playtime;
    }
    public int getMinutes_on_bench() {
        return minutes_on_bench;
    }
}
