class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = ""; // Initialize the result string
        int i = 0; // Initialize the index
        // Loop until all characters from both strings are processed
        while (i < word1.length() || i < word2.length()) {
            // If the current index is within the bounds of word1, append the character to result
            if (i < word1.length()) {
                result += word1[i];
            }
            // If the current index is within the bounds of word2, append the character to result
            if (i < word2.length()) {
                result += word2[i];
            }
            // Increment the index to move to the next character
            i++;
        }
        // Return the merged string
        return result;
    }
};
