#include <iostream>
#include <limits.h>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Special cases
        if (divisor == 0) return INT_MAX; // Division by zero
        if (dividend == INT_MIN && divisor == -1) return INT_MAX; // Overflow

        // Use long long to handle overflow cases
        long long dividendLong = abs((long long)dividend);
        long long divisorLong = abs((long long)divisor);

        int result = 0;
        while (dividendLong >= divisorLong) {
            long long temp = divisorLong, multiple = 1;
            while (dividendLong >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dividendLong -= temp;
            result += multiple;
        }

        // Determine the sign of the result
        return (dividend > 0) == (divisor > 0) ? result : -result;
    }
};

int main() {
    Solution solution;

    // Test case
    int dividend = 10;
    int divisor = 3;
    int result = solution.divide(dividend, divisor);
    std::cout << result << std::endl; // Expected output: 3

    // Another test case
    dividend = 7;
    divisor = -3;
    result = solution.divide(dividend, divisor);
    std::cout << result << std::endl; // Expected output: -2

    return 0;
}
