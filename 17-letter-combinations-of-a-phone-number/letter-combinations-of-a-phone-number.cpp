class Solution {
public:
    std::vector<std::string> letterCombinations(std::string d) {
        if (d.empty()) {
            return {};
        }

        std::unordered_map<char, std::string> mp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        std::vector<std::string> result;
        result.push_back("");

        for (char digit : d) {
            std::vector<std::string> temp;
            for (char letter : mp[digit]) {
                for (std::string combination : result) {
                    temp.push_back(combination + letter);
                }
            }
            result = temp;
        }

        return result;
    }
};