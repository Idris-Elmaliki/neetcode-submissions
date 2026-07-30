class Solution {
public:
    bool isPalindrome(string s) { 
        std::string s2 = ""; 

        for(auto c : s) {
            std::cout << c << ", is a letter: " << std::boolalpha << isalpha(c) << '\n'; 
            if(isalnum(c)) {
                s2.append(1, tolower(c)); 
            }
        }

        std::cout << s2 << '\n'; 

        int l = 0, r = s2.size() - 1; 

        while(l < r) {
            char left = s2[l]; 
            char right = s2[r]; 

            std::cout << "Left char: " << left << "\nRight char: " << right << std::endl; 

            if(left != right) {
                return false; 
            }

            ++l; 
            --r; 
        }

        return true; 
    }
};
