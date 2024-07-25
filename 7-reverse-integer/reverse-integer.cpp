#include <climits> // Include the header file for INT_MAX and INT_MIN

class Solution {
public:
    int reverse(int x) {
        long r = 0; // Use long to handle intermediate results

        while (x != 0) {
            r = r * 10 + x % 10; // Append the last digit of x to r
            x /= 10; // Remove the last digit from x
        }
           
        // Check if the result is within the 32-bit signed integer range
        if (r > INT_MAX || r < INT_MIN) {
            return 0; // Return 0 to indicate overflow
        }
        
        return static_cast<int>(r); // Cast the result back to int
    }
};
