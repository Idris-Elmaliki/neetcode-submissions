class Solution {
    std::vector<std::string> memo; 
    std::string s = "";

    std::string helper(const int index) {
        int l = index, r = index; 

        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            --l;
            ++r; 
        }

        std::string str = s.substr(l + 1, r - l - 1);

        return str; 
    }

    std::string helper(const int& left, const int& right) {
        int l = left, r = right; 

        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            --l;
            ++r; 
        }

        std::string str = s.substr(l + 1, r - l - 1);

        return str; 
    }

    // memo: an array, where each ndex holds the max size palindrome from index 0 -> n
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1)
            return s;

        this->s = s; 
        memo.resize(s.size());

        memo[0] = s.substr(0, 1);

        string s1 = helper(1);
        string s2 = helper(0, 1);

        std::string res1 = (s1.size() > s2.size() ? s1 : s2);
        memo[1] = (res1.size() > memo[0].size() ? res1 : memo[0]);

        for(int i = 2; i < s.size(); i++) {
            std::string odd = helper(i);
            std::string even = helper(i-1, i); 

            std::string curr = (odd.size() > even.size()) ? odd : even;

            if(curr.size() > memo[i - 1].size()) {
                memo[i] = curr;
            }
            else {
                memo[i] = memo[i-1]; 
            }
        }

        return memo[s.size() - 1];
    }
};