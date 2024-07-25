class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0; // Initialize left pointer at the start of the array
        int right = height.size() - 1; // Initialize right pointer at the end of the array
        int maxArea = 0; // Initialize maxArea to 0

        while (left < right) { // Loop until the two pointers meet
            // Calculate the current area
            int currentArea = min(height[left], height[right]) * (right - left);
            // Update maxArea if currentArea is greater
            maxArea = max(maxArea, currentArea);

            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea; // Return the maximum area found
    }
};
