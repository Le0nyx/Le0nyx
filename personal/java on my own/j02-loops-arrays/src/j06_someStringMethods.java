public class j06_someStringMethods {
    public static void main(String[] args){
        String name = "World";
        System.out.println("\nThe String is \"" +name+ "\"");
        boolean whatis = name.equals("World");

        System.out.println("The bool is: "+whatis);
        System.out.println("Length of string is: "+name.length()); //ignores the space
        System.out.println("Char at 2. point in String array: "+name.charAt(2)); //starts at 0
        System.out.println("Found the char 'o' at index: "+name.indexOf("o"));
        System.out.println("Seeing if the String is empty: "+name.isEmpty());
        System.out.println("\nThe String in all upper: "+name.toUpperCase());
        System.out.println("The String in all upper: "+name.toLowerCase());
        //System.out.println(name.trim()); //cuts out the unnecessary spaces
        System.out.println("\n"+name+ " is original");
        //name = name.replace("o", "e");
        System.out.println(name.replace("o", "e")+ " is modified");
    }
}
