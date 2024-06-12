public class Solution {
    public String intToRoman(int num) {
        int[] values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String[] symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        StringBuilder roman = new StringBuilder();
        
        for (int i = 0; i < values.length && num > 0; i++) {
            while (num >= values[i]) {
                num -= values[i];
                roman.append(symbols[i]);
            }
        }
        
        return roman.toString();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.intToRoman(3));    // Output: "III"
        System.out.println(solution.intToRoman(58));   // Output: "LVIII"
        System.out.println(solution.intToRoman(1994)); // Output: "MCMXCIV"
    }
}
