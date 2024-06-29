public class Solution {
    public int divide(int dividend, int divisor) {
        // Special cases
        if (divisor == 0) {
            return Integer.MAX_VALUE; // Division by zero
        }
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE; // Overflow
        }

        // Use long to handle overflow cases
        long dividendLong = Math.abs((long) dividend);
        long divisorLong = Math.abs((long) divisor);

        int result = 0;
        while (dividendLong >= divisorLong) {
            long temp = divisorLong, multiple = 1;
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

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case
        int dividend = 10;
        int divisor = 3;
        int result = solution.divide(dividend, divisor);
        System.out.println(result); // Expected output: 3

        // Another test case
        dividend = 7;
        divisor = -3;
        result = solution.divide(dividend, divisor);
        System.out.println(result); // Expected output: -2
    }
}

