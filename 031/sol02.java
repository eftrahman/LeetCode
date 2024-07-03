import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        int n = words.length, m = words[0].length(); // Number of words, length of each word

        // Create a HashMap to store word frequencies in the dictionary
        HashMap<String, Integer> wordFreq = new HashMap<>();
        for (String word : words) {
            wordFreq.put(word, wordFreq.getOrDefault(word, 0) + 1);
        }

        // Iterate through all possible starting positions
        for (int i = 0; i <= s.length() - n * m; i++) {
            HashMap<String, Integer> windowFreq = new HashMap<>(); // HashMap for sliding window

            // Fill the sliding window with frequencies of encountered words
            for (int j = 0; j < n; j++) {
                String word = s.substring(i + j * m, i + (j + 1) * m);
                if (!wordFreq.containsKey(word) || windowFreq.getOrDefault(word, 0) > wordFreq.get(word)) {
                    // Word not found in dictionary or exceeds frequency limit
                    break;
                }
                windowFreq.put(word, windowFreq.getOrDefault(word, 0) + 1);
            }

            // Check if all word frequencies match in the window
            if (windowFreq.size() == wordFreq.size()) {
                result.add(i);
            }
        }

        return result;
    }
}

