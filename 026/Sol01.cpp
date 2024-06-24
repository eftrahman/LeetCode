#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int index = 1; // Points to the position of the next unique element

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[index] = nums[i];
                index++;
            }
        }

        return index;
    }
};

// Helper function to print the array
void printArray(const vector<int>& nums, int length) {
    for (int i = 0; i < length; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Test case
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int length = solution.removeDuplicates(nums);
    printArray(nums, length); // Expected output: 0 1 2 3 4

    return 0;
}
