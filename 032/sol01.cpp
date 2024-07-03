#include <stack>
#include <string>

using namespace std;

int longestValidParentheses(string s) {
    int maxLength = 0;
    stack<int> stk; // Stack to store opening parenthesis indices

    // Iterate through the string
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];

        // If opening parenthesis, push its index onto the stack
        if (ch == '(') {
            stk.push(i);
        } else if (ch == ')') { // If closing parenthesis
            // Check if there's a matching opening parenthesis
            if (!stk.empty() && s[stk.top()] == '(') {
                stk.pop(); // Matching pair found, remove both from consideration
                maxLength = max(maxLength, i - stk.top()); // Update max length
            } else {
                // Mismatched closing parenthesis, update stack for next valid sequence
                stk.push(i);
            }
        }
    }

    // Handle cases where there are extra opening parentheses at the end
    if (!stk.empty()) {
        int lastOpenIndex = stk.top();
        maxLength = max(maxLength, s.size() - 1 - lastOpenIndex);
    }

    return maxLength;
}

