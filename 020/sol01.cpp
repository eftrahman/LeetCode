#include <iostream>
#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> matchingParentheses = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char ch : s) {
            if (matchingParentheses.count(ch)) {
                if (stack.empty() || stack.top() != matchingParentheses[ch]) {
                    return false;
                }
                stack.pop();
            } else {
                stack.push(ch);
            }
        }

        return stack.empty();
    }
};

int main() {
    Solution solution;
    std::string s1 = "()";
    std::string s2 = "()[]{}";
    std::string s3 = "(]";
    std::string s4 = "([)]";
    std::string s5 = "{[]}";

    std::cout << "Is valid (s1): " << std::boolalpha << solution.isValid(s1) << std::endl; // true
    std::cout << "Is valid (s2): " << std::boolalpha << solution.isValid(s2) << std::endl; // true
    std::cout << "Is valid (s3): " << std::boolalpha << solution.isValid(s3) << std::endl; // false
    std::cout << "Is valid (s4): " << std::boolalpha << solution.isValid(s4) << std::endl; // false
    std::cout << "Is valid (s5): " << std::boolalpha << solution.isValid(s5) << std::endl; // true

    return 0;
}
