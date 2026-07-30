class Solution {
public:
    bool isPalindrome(string s) { 
        std::string s2 = ""; 

        for(auto c : s) {
            if(isalpha(c)) {
                s2.append(1, tolower(c)); 
            }
            else if(isdigit(c)) {
                s2.append(1, c); 
            }
        }

        int l = 0, r = s2.size() - 1; 

        while(l < r) {
            char left = s2[l]; 
            char right = s2[r]; 

            if(left != right) {
                return false; 
            }

            ++l; 
            --r; 
        }

        return true; 
    }
};
