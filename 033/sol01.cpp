#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Check if the left half is sorted
            if (nums[left] <= nums[mid]) {
                // Check if the target is in the left half
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else { // Right half is sorted
                // Check if the target is in the right half
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1; // Target not found
    }
};

int main() {
    Solution solution;

    // Test case 1
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int result = solution.search(nums, target);
    std::cout << "Index of target " << target << " is: " << result << std::endl; // Expected output: 4

    // Test case 2
    nums = {4, 5, 6, 7, 0, 1, 2};
    target = 3;
    result = solution.search(nums, target);
    std::cout << "Index of target " << target << " is: " << result << std::endl; // Expected output: -1

    // Test case 3
    nums = {1};
    target = 0;
    result = solution.search(nums, target);
    std::cout << "Index of target " << target << " is: " << result << std::endl; // Expected output: -1

    return 0;
}
