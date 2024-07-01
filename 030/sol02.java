import java.util.*;

public class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        if (s == null || s.length() == 0 || words == null || words.length == 0) {
            return result;
        }

        int wordLength = words[0].length();
        int wordCount = words.length;
        int totalLength = wordLength * wordCount;

        if (s.length() < totalLength) {
            return result;
        }

        // Create a frequency map for the words
        Map<String, Integer> wordMap = new HashMap<>();
        for (String word : words) {
            wordMap.put(word, wordMap.getOrDefault(word, 0) + 1);
        }

        // Iterate over the string s
        for (int i = 0; i <= s.length() - totalLength; i++) {
            Map<String, Integer> seenWords = new HashMap<>();
            int j = 0;

            // Check if a valid substring starting at i exists
            while (j < wordCount) {
                String word = s.substring(i + j * wordLength, i + (j + 1) * wordLength);
                if (wordMap.containsKey(word)) {
                    seenWords.put(word, seenWords.getOrDefault(word, 0) + 1);
                    if (seenWords.get(word) > wordMap.get(word)) {
                        break;
                    }
                } else {
                    break;
                }
                j++;
            }

            if (j == wordCount) {
                result.add(i);
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case
        String s = "barfoothefoobarman";
        String[] words = {"foo", "bar"};
        List<Integer> result = solution.findSubstring(s, words);
        for (int index : result) {
            System.out.println(index); // Expected output: 0, 9
        }

        // Another test case
        s = "wordgoodgoodgoodbestword";
        words = new String[]{"word", "good", "best", "word"};
        result = solution.findSubstring(s, words);
        for (int index : result) {
            System.out.println(index); // Expected output: (empty as no valid substring)
        }
    }
}
