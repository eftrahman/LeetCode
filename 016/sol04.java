import java.util.Arrays;

public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                if (currentSum == target) {
                    return currentSum; // Found the exact target
                }

                if (Math.abs(currentSum - target) < Math.abs(closestSum - target)) {
                    closestSum = currentSum;
                }

                if (currentSum < target) {
                    left++;
                } else {
                    right--;
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

