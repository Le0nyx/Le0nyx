public class j05_2Darray {
    public static void main(String[] args){
        String[][] cars = {{"Mazda", "smoll"}, {"Audi", "R8"}, {"Honda", "Civic"}};

        for(int i = 0;i< cars.length;i++){
            for(int j = 0;j<cars[i].length;j++){
                System.out.print(cars[i][j]+", ");
            }
            System.out.println();
        }

        System.out.println("\nagain: ");
        for (String[] car : cars) { //alternate version intellij told me
            for (String s : car) {
                System.out.print(s + ", ");
            }
            System.out.println();
        }
    }
}
