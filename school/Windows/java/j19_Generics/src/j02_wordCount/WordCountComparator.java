package j02_wordCount;

import java.util.Comparator;

public class WordCountComparator implements Comparator<String>{
    @Override
    public int compare(String s1, String s2) {
        return s2.compareTo(s1); // Reverse alphabetical order
    }
}
