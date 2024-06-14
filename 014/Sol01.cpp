#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }
};

int main() {
    Solution solution;
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << solution.longestCommonPrefix(strs1) << endl; // Output: "fl"
    
    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << solution.longestCommonPrefix(strs2) << endl; // Output: ""
    
    return 0;
}
