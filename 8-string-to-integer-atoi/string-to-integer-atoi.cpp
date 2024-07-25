class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long ans = 0;

        // Skip leading whitespace
        while (i < s.length() && s[i] == ' ')
            i++;

        // Check for optional sign
        if (i < s.length() && s[i] == '-') {
            sign = -1;
            i++;
        } else if (i < s.length() && s[i] == '+') {
            i++;
        }

        // Process numeric digits
        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');
            
            // Check for overflow and underflow
            if (ans * sign > INT_MAX) {
                return INT_MAX;
            } else if (ans * sign < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        // Apply sign to the result
        return static_cast<int>(ans * sign);
    }
};