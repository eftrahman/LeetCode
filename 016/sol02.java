import java.util.Arrays;

public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int n = nums.length;
        if (n < 3) return 0;

        Arrays.sort(nums);
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    int currentSum = nums[i] + nums[j] + nums[k];
                    if (Math.abs(currentSum - target) < Math.abs(closestSum - target)) {
                        closestSum = currentSum;
                    }
                }
            }
        }

        return closestSum;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        int[] nums1 = {-1, 2, 1, -4};
        int target1 = 1;
        System.out.println("Closest sum: " + solution.threeSumClosest(nums1, target1)); // Output: 2

        int[] nums2 = {0, 0, 0};
        int target2 = 1;
        System.out.println("Closest sum: " + solution.threeSumClosest(nums2, target2)); // Output: 0
    }
}

