public class Solution {
    public int longestValidParentheses(String s) {
        int maxLength = 0;
        Stack<Integer> stk = new Stack<>(); // Stack to store opening parenthesis indices

        // Iterate through the string
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);

            // If opening parenthesis, push its index onto the stack
            if (ch == '(') {
                stk.push(i);
            } else if (ch == ')') { // If closing parenthesis
                // Check if there's a matching opening parenthesis
                if (!stk.isEmpty() && s.charAt(stk.peek()) == '(') {
                    stk.pop(); // Matching pair found, remove both from consideration
                    maxLength = Math.max(maxLength, i - stk.peek()); // Update max length
                } else {
                    // Mismatched closing parenthesis, update stack for next valid sequence
                    stk.push(i);
                }
            }
        }

        // Handle cases where there are extra opening parentheses at the end
        if (!stk.isEmpty()) {
            int lastOpenIndex = stk.peek();
            maxLength = Math.max(maxLength, s.length() - 1 - lastOpenIndex);
        }

        return maxLength;
    }
}

