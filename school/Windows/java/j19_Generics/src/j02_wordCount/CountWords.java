package j02_wordCount;

import java.io.File;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class CountWords {
    public static void main(String[] args) throws Exception {
        TreeMap<String, Integer> map = new TreeMap<>();
        int minlen = 3;
        int maxlen = 6;

        // Read from file alice.txt
        StringBuilder message = new StringBuilder();
        Scanner sc = new Scanner(new File("alice.txt"));
        while (sc.hasNextLine()) {
            message.append(sc.nextLine() + " ");
        }
        sc.close();

        // Split the string and exclude special characters (even multiple in a row)
        String[] words = message.toString().split("[\\s.()`,´;:_\"!'#?+\\- ]+");

        for (String word : words) {
            if (word.length() >= minlen && word.length() <= maxlen) {
                map.put(word.toLowerCase(), map.getOrDefault(word.toLowerCase(), 0) + 1);
            }
        }
        // normal print
        //for(String word : map.keySet()) { System.out.println(map.get(word)); }

        // print by count
        // printByAmount(map);

        // new treemap for that
        TreeMap<String, Integer> reverseMap = new TreeMap<>(new WordCountComparator());
        reverseMap.putAll(map);

        // Print in other way around z -> a alphabetical order
        for (String word : reverseMap.keySet()) {
            System.out.println(reverseMap.get(word) + " - " + word);
        }
    }

    public static void printByAmount(Map<String, Integer> map) {
        int target = 0;
        for (int num : map.values()) {
            if (num > target) {
                target = num;
            }
        }

        // print all from highest value to 1 and 1
        for (;target >= 1; target--) {
            for (String word : map.keySet()) {
                if (map.get(word) == target) {
                    System.out.println(target + " - " + word);
                }
            }
        }
    }
}
