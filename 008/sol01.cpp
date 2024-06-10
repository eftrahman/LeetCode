class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int n = str.size();
        
        // Step 1: Skip leading whitespace
        while (i < n && isspace(str[i])) {
            i++;
        }
        
        // Step 2: Check for optional sign
        int sign = 1;
        if (i < n && (str[i] == '+' || str[i] == '-')) {
            sign = (str[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Step 3: Convert digits to integer
        long long result = 0;
        while (i < n && isdigit(str[i])) {
            result = result * 10 + (str[i] - '0');
            
            // Step 4: Handle overflow and underflow
            if (result * sign > INT_MAX) {
                return INT_MAX;
            } else if (result * sign < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }
        
        return result * sign;
    }
};

