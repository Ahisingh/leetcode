class Solution {
public:
    void nextPermutation(vector<int>& v) {
        if(v.size() == 1) return;
        if(v.size() == 2) {
            swap(v[0], v[1]);
            return;
        }

        int i = v.size() - 2;
        // Find the first decreasing element from the end
        while(i >= 0 && v[i] >= v[i + 1]) {
            i--;
        }

        // If the entire list is non-increasing, reverse it
        if(i < 0) {
            reverse(v.begin(), v.end());
            return;
        }

        // Sort the elements to the right of the identified element
        sort(v.begin() + i + 1, v.end());

        // Find the smallest element greater than v[i] and swap
        for(int j = i + 1; j < v.size(); j++) {
            if(v[i] < v[j]) {
                swap(v[i], v[j]);
                break;
            }
        }
    }
};
