#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // Define the value and symbol pairs
        const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string roman;
        for (int i = 0; i < 13 && num > 0; ++i) {
            while (num >= values[i]) {
                num -= values[i];
                roman += symbols[i];
            }
        }
        return roman;
    }
};

int main() {
    Solution solution;
    cout << solution.intToRoman(3) << endl;    // Output: "III"
    cout << solution.intToRoman(58) << endl;   // Output: "LVIII"
    cout << solution.intToRoman(1994) << endl; // Output: "MCMXCIV"
    return 0;
}
