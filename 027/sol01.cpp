#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0; // Points to the position of the next element to be kept

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
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
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    int length = solution.removeElement(nums, val);
    printArray(nums, length); // Expected output: 2 2

    return 0;
}
