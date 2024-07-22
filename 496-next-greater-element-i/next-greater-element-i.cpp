#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        vector<int> v; // To store the result
        map<int, int> m; // Maps elements of b to their indices

        // Populate the map with elements of b and their indices
        for (int i = 0; i < b.size(); i++) {
            m[b[i]] = i; // No need for +1, use 0-based indexing
        }

        // Iterate over each element in a
        for (int i = 0; i < a.size(); i++) {
            int num = -1; // Default value when no greater element is found

            // Check if the element exists in the map
            if (m.count(a[i])) {
                int startIndex = m[a[i]] + 1; // Start searching after the current element
                // Find the next greater element
                for (int j = startIndex; j < b.size(); j++) {
                    if (b[j] > a[i]) {
                        num = b[j];
                        break;
                    }
                }
            }
            
            // Add the result for a[i] to the vector
            v.push_back(num);
        }

        return v; // Return the result vector
    }
};
