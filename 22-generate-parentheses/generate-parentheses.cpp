class Solution {
public:
    void backtrack(string& current, int open, int close, int max, vector<string>& result) {
        if (current.size() == max * 2) {
            result.push_back(current);
            return;
        }

        if (open < max) {
            current.push_back('(');
            backtrack(current, open + 1, close, max, result);
            current.pop_back();
        }

        if (close < open) {
            current.push_back(')');
            backtrack(current, open, close + 1, max, result);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(current, 0, 0, n, result);
        return result;
    }
};
