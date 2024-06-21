import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

public class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        Map<Character, Character> matchingParentheses = new HashMap<>();
        matchingParentheses.put(')', '(');
        matchingParentheses.put('}', '{');
        matchingParentheses.put(']', '[');

        for (char ch : s.toCharArray()) {
            if (matchingParentheses.containsKey(ch)) {
                char topElement = stack.isEmpty() ? '#' : stack.pop();
                if (topElement != matchingParentheses.get(ch)) {
                    return false;
                }
            } else {
                stack.push(ch);
            }
        }

        return stack.isEmpty();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String s1 = "()";
        String s2 = "()[]{}";
        String s3 = "(]";
        String s4 = "([)]";
        String s5 = "{[]}";

        System.out.println("Is valid (s1): " + solution.isValid(s1)); // true
        System.out.println("Is valid (s2): " + solution.isValid(s2)); // true
        System.out.println("Is valid (s3): " + solution.isValid(s3)); // false
        System.out.println("Is valid (s4): " + solution.isValid(s4)); // false
        System.out.println("Is valid (s5): " + solution.isValid(s5)); // true
    }
}
