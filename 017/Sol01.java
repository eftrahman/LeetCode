import java.util.ArrayList;
import java.util.List;

public class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<>();
        if (digits == null || digits.length() == 0) {
            return result;
        }

        String[] mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        backtrack(result, digits, "", 0, mapping);
        return result;
    }

    private void backtrack(List<String> result, String digits, String current, int index, String[] mapping) {
        if (index == digits.length()) {
            result.add(current);
            return;
        }

        String letters = mapping[digits.charAt(index) - '0'];
        for (char letter : letters.toCharArray()) {
            backtrack(result, digits, current + letter, index + 1, mapping);
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        
        String digits1 = "23";
        List<String> result1 = solution.letterCombinations(digits1);
        System.out.println(result1); // Expected output: [ad, ae, af, bd, be, bf, cd, ce, cf]

        String digits2 = "";
        List<String> result2 = solution.letterCombinations(digits2);
        System.out.println(result2); // Expected output: []

        String digits3 = "2";
        List<String> result3 = solution.letterCombinations(digits3);
        System.out.println(result3); // Expected output: [a, b, c]
    }
}
