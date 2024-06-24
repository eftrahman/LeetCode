public class Solution {
    public int removeElement(int[] nums, int val) {
        int index = 0; // Points to the next position to place a non-val element

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != val) {
                nums[index] = nums[i];
                index++;
            }
        }

        return index;
    }

    // Helper function to print the array
    public static void printArray(int[] nums, int length) {
        for (int i = 0; i < length; i++) {
            System.out.print(nums[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case
        int[] nums = {3, 2, 2, 3};
        int val = 3;
        int length = solution.removeElement(nums, val);
        printArray(nums, length); // Expected output: 2 2

        // Another test case
        int[] nums2 = {0,1,2,2,3,0,4,2};
        int val2 = 2;
        int length2 = solution.removeElement(nums2, val2);
        printArray(nums2, length2); // Expected output: 0 1 3 0 4
    }
}
