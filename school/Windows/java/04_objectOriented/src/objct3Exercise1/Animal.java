package objct3Exercise1;

public class Animal {
    private String name;
    private int age;
    private String species;

    Animal(String name, int age, String species) {
        this.name = name;
        this.age = age;
        this.species = species;
    }

    public void makeNoise() {
        System.out.println("The animal is making sound");
    }



    public String getName(){
        return name;
    }
    public int getAge(){
        return age;
    }
    public String getSpecies(){
        return species;
    }

    public void setName(String name){
        this.name = name;
    }
    public void setAge(int age){
        this.age = age;
    }
    public void setSpecies(String species){
        this.species = species;
    }
}
