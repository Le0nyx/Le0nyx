package objct3Exercise1;

public class Main {
    public static void main(String[] args) {
        Animal bear = new Animal("Fred", 14, "Grizzly bear");

        System.out.println(bear.getName());
        System.out.println(bear.getAge());
        System.out.println(bear.getSpecies());

        bear.makeNoise();

        Animal[] animals = new Animal[5];
        String animalName = "Fredderico";
        for(int i = 0;i<5;i++){
            animals[i] = new Animal(animalName + " #" + i, i, "Grizzly bear");
        }

        animals[3].setSpecies("Brownbear");
        animals[2].setName("Fred");
        animals[0].setAge(45);

        System.out.println("--------");

        for(Animal a : animals){
            System.out.println(a.getName());
            System.out.println(a.getAge());
            System.out.println(a.getSpecies());
            System.out.println("------------------");
        }

        int count = 0;
        for(Animal animal : animals){
            if(animal.getAge() > 10){
                count ++;
            }
        }

        System.out.println("Animals above the age of 10: "+count);
    }
}
