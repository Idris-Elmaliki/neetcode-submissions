class Solution {
    std::unordered_map<char, std::string> backMap {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    std::string current = "";
    std::vector<std::string> res; 

    void backTracking(int index, const std::string& digits) {
        if(current.size() == digits.size()) {
            res.emplace_back(current);
            return; 
        }

        for(int i = index; i < digits.size(); i++) {
            for(const auto& str : backMap[digits[i]]) {
                current.push_back(str);
                backTracking(i + 1, digits);

                current.pop_back();
            }
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};

        backTracking(0, digits);

        return res; 
    }
};
