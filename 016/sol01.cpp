#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>  // For abs()

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) return 0;

        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    int currentSum = nums[i] + nums[j] + nums[k];
                    if (abs(currentSum - target) < abs(closestSum - target)) {
                        closestSum = currentSum;
                    }
                }
            }
        }

        return closestSum;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {-1, 2, 1, -4};
    int target1 = 1;
    cout << "Closest sum: " << solution.threeSumClosest(nums1, target1) << endl; // Output: 2

    vector<int> nums2 = {0, 0, 0};
    int target2 = 1;
    cout << "Closest sum: " << solution.threeSumClosest(nums2, target2) << endl; // Output: 0

    return 0;
}
