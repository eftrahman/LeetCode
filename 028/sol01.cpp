#include <iostream>
#include <string>

class Solution {
public:
    int strStr(const std::string& haystack, const std::string& needle) {
        if (needle.empty()) {
            return 0;
        }
        
        int hLen = haystack.length();
        int nLen = needle.length();
        
        if (nLen > hLen) {
            return -1;
        }

        for (int i = 0; i <= hLen - nLen; ++i) {
            if (haystack.substr(i, nLen) == needle) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution solution;

    // Test case
    std::string haystack = "hello";
    std::string needle = "ll";
    int result = solution.strStr(haystack, needle);
    std::cout << result << std::endl; // Expected output: 2

    // Another test case
    std::string haystack2 = "aaaaa";
    std::string needle2 = "bba";
    int result2 = solution.strStr(haystack2, needle2);
    std::cout << result2 << std::endl; // Expected output: -1

    return 0;
}
