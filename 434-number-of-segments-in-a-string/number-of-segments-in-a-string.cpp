class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s); // Create a stringstream object with the input string s
        string str;         // Declare a string to hold each word
        int count = 0;      // Initialize count to 0
        
        // Loop to extract words from the stringstream
        while (ss >> str) {
            count++;        // Increment count for each word
        }
        
        return count;       // Return the total number of words
    }
};
