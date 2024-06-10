#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long reversed = 0;
        while (x != 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
            // Check for overflow and underflow
            if (reversed > INT_MAX || reversed < INT_MIN) {
                return 0;
            }
        }
        return static_cast<int>(reversed);
    }
};

int main() {
    Solution solution;
    int testNumber = 123;
    cout << solution.reverse(testNumber) << endl;  // Output: 321

    testNumber = -123;
    cout << solution.reverse(testNumber) << endl;  // Output: -321

    testNumber = 120;
    cout << solution.reverse(testNumber) << endl;  // Output: 21

    testNumber = 0;
    cout << solution.reverse(testNumber) << endl;  // Output: 0

    testNumber = 1534236469;
    cout << solution.reverse(testNumber) << endl;  // Output: 0 (due to overflow)

    return 0;
}

