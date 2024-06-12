#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int result = 0;
        int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            if (i < n - 1 && roman[s[i]] < roman[s[i + 1]]) {
                result -= roman[s[i]];
            } else {
                result += roman[s[i]];
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.romanToInt("III") << endl;    // Output: 3
    cout << solution.romanToInt("LVIII") << endl;  // Output: 58
    cout << solution.romanToInt("MCMXCIV") << endl;// Output: 1994
    return 0;
}
