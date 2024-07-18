class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1; // Initialize i to the last index of num1
        int j = num2.size() - 1; // Initialize j to the last index of num2
        string ans = ""; // Initialize the result string
        int carry = 0; // Initialize the carry to 0

        // Loop while there are digits to process or there is a carry
        while (i >= 0 || j >= 0 || carry) {
            long sum = 0; // Initialize sum for this digit

            // Add digit from num1 if i is a valid index
            if (i >= 0) {
                sum += num1[i] - '0';
                i--; // Move to the next digit
            }

            // Add digit from num2 if j is a valid index
            if (j >= 0) {
                sum += num2[j] - '0';
                j--; // Move to the next digit
            }

            // Add the carry from the previous digit addition
            sum += carry;

            // Update carry for the next digit addition
            carry = sum / 10;

            // Append the last digit of sum to the result string
            ans += to_string(sum % 10);
        }

        // Reverse the result string to get the correct order
        reverse(ans.begin(), ans.end());
        return ans; // Return the final result
    }
};
