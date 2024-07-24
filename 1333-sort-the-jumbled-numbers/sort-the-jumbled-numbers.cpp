class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int numCount = nums.size(); // Number of elements in nums
        vector<pair<int, int>> mappedNumAndIndex(numCount); // To store mapped number and original index

        // Iterate through each number in nums
        for (int i = 0; i < numCount; ++i) {
            int originalNum = nums[i]; // The current number
            string mappedNumStr = ""; // To build the mapped number as a string

            // Handle case where the number is 0
            if (originalNum == 0) {
                mappedNumStr = to_string(mapping[0]); // Directly use the mapping for 0
            } else {
                // Convert the number to a mapped string
                while (originalNum > 0) {
                    int digit = originalNum % 10; // Extract the last digit
                    mappedNumStr = to_string(mapping[digit]) + mappedNumStr; // Add the mapped digit to the string
                    originalNum /= 10; // Remove the last digit
                }
            }

            // Convert the mapped string back to an integer
            int mappedNum = stoi(mappedNumStr); // Mapped number as an integer
            mappedNumAndIndex[i] = {mappedNum, i}; // Store mapped number and original index
        }

        // Sort the vector of pairs based on the mapped number
        sort(mappedNumAndIndex.begin(), mappedNumAndIndex.end());

        // Construct the sorted nums vector
        vector<int> sortedNums;
        for (const auto& pair : mappedNumAndIndex) {
            sortedNums.push_back(nums[pair.second]); // Add original numbers in sorted order
        }

        return sortedNums; // Return the sorted list
    }
};
