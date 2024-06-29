public class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.isEmpty()) {
            return 0;
        }

        int hLen = haystack.length();
        int nLen = needle.length();

        if (nLen > hLen) {
            return -1;
        }

        for (int i = 0; i <= hLen - nLen; i++) {
            if (haystack.substring(i, i + nLen).equals(needle)) {
                return i;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case
        String haystack = "hello";
        String needle = "ll";
        int result = solution.strStr(haystack, needle);
        System.out.println(result); // Expected output: 2

        // Another test case
        String haystack2 = "aaaaa";
        String needle2 = "bba";
        int result2 = solution.strStr(haystack2, needle2);
        System.out.println(result2); // Expected output: -1
    }
}
