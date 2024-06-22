#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        generate(result, "", 0, 0, n);
        return result;
    }

private:
    void generate(std::vector<std::string>& result, std::string current, int open, int close, int max) {
        if (current.length() == max * 2) {
            result.push_back(current);
            return;
        }

        if (open < max) {
            generate(result, current + "(", open + 1, close, max);
        }
        if (close < open) {
            generate(result, current + ")", open, close + 1, max);
        }
    }
};

int main() {
    Solution solution;
    int n = 3;
    std::vector<std::string> result = solution.generateParenthesis(n);

    for (const std::string& s : result) {
        std::cout << s << std::endl;
    }

    return 0;
}
