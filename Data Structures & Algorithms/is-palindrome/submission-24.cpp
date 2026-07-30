class Solution {
public:
    bool isPalindrome(string s) { 
        std::string s2; 

        for(auto c : s) {
            if(std::isalnum(c)) {
                s2 += tolower(c); 
            }
        }

        int l = 0, r = s2.size() - 1; 

        while(l < r) {
            if(s2[l] != s2[r]) {
                return false; 
            }

            ++l; 
            --r; 
        }

        return true; 
    }
};
