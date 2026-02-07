import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

public class HashTable {
    private final int capacity = 28;
    private int size;
    private ArrayList<ArrayList<Student>> table;
    // arraylist in a arraylist cuz if double / kollision

    public HashTable() {
        size = 0;
        table = new ArrayList<>(capacity);
        for (int i = 0; i < capacity; i++) {
            table.add(new ArrayList<>());
        }
    }

    private int hash(String key) {
        int hash = 0;
        for (int i = 0; i < key.length(); i++) {
            hash = (31 * hash + key.charAt(i)) % capacity;
        }
        return Math.abs(hash);
    }

    public boolean addStudent(Student s) {
        String key = s.getLastName() + s.getBirthDate();
        int index = hash(key);
        ArrayList<Student> bucket = table.get(index);

        for (Student student : bucket) { // check if already exists
            if (student.getLastName().equals(key)) {
                return false; // DONT ADD. is double
            }
        }

        bucket.add(s); // add after the check if sure that not in arrlist
        size++; // table fills up
        return true; // if added
    }

    public Student getStudent(String lastName) {
        int index = hash(lastName);
        ArrayList<Student> bucket = table.get(index);

        for (Student s : bucket) {
            if (s.getLastName().equals(lastName)) {
                return s;
            }
        }

        return null;
    }

    public boolean removeStudent(String lastName) {
        int index = hash(lastName);
        ArrayList<Student> bucket = table.get(index);
        Iterator<Student> iterator = bucket.iterator();
        while (iterator.hasNext()) {
            Student s = iterator.next();
            if (s.getLastName().equals(lastName)) {
                iterator.remove();
                size--;
                return true;
            }
        }
        return false;
    }

    public double loadFactor() {
        return (double) size / capacity;
    }

    // Laden der SchülerInnen aus einer Datei.
    // Es wird angenommen, dass jede Zeile die Attribute (Vorname, Nachname, Geburtsdatum, Adresse)
    // enthält, getrennt durch Kommas.
    public void loadFromFile(String file) {
        try (Scanner scanner = new Scanner(new File(file))) {
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] parts = line.split(",");
                if (parts.length >= 4) {
                    String firstName = parts[0].trim();
                    String lastName = parts[1].trim();
                    String birthDate = parts[2].trim();
                    String address = parts[3].trim();
                    Student s = new Student(firstName, lastName, birthDate, address);
                    if (!addStudent(s)) {
                        System.out.println("Duplikat gefunden: " + s);
                    }
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println("Datei nicht gefunden: " + file);
        }
    }
}
