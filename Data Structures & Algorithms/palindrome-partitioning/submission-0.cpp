class Solution {
    std::string str = "";

    std::vector<std::string> current; 
    std::vector<std::vector<std::string>> res; 

    bool isPalindrome(const std::string& s) {
        int l = 0, r = s.size() - 1; 

        while(l < r) {
            if(s[l] != s[r])
                return false; 

            ++l; 
            --r; 
        }

        return true; 
    }
    
    void backTracking(int index) {
        if(index == str.size()) {
            res.push_back(current);
            return; 
        }

        for(int i = index; i < str.size(); i++) {
            if(isPalindrome(str.substr(index, i + 1 - index))) {
                current.emplace_back(str.substr(index, i + 1 - index)); 

                backTracking(i + 1);

                current.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        str = s; 
        backTracking(0); 

        return res;
    }
};
