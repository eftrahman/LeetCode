class Solution {
    public boolean isPalindrome(int x) {
                if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedNumber = 0;
        int original = x;

        // Reverse the integer partially
        while (x > reversedNumber) {
            reversedNumber = reversedNumber * 10 + x % 10;
            x /= 10;
        }

        // Check if the original number or the number without the middle digit (for odd length numbers) is equal to the reversed number
        return x == reversedNumber || x == reversedNumber / 10;
    }
}
