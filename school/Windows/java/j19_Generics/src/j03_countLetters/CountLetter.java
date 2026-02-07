package j03_countLetters;

import j02_wordCount.WordCountComparator;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class CountLetter{
    public static void main(String[] args) throws FileNotFoundException {
        HashMap<Character, Integer> map = new HashMap<>();

        StringBuilder message = new StringBuilder();
        Scanner sc = new Scanner(new File("alice.txt"));
        while (sc.hasNextLine()) {
            message.append(sc.nextLine().toLowerCase());
        }
        sc.close();

        for (int i = 0; i < message.length(); i++) {
            char c = message.charAt(i);
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        // Print
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            System.out.println(entry.getKey() + " - " + entry.getValue());
        }
    }
}
