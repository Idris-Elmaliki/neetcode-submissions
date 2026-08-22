class Solution {
    int res = 0;
    std::string s = "";

    // memo, a map that holds each unique palindrome that starts in a certain index

    void helper(const int index) {
        int l = index, r = index;

        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            --l;
            ++r;

            ++res; 
        }
    }

    std::string helper(const int& left, const int& right) {
        int l = left, r = right;

        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            --l;
            ++r;

            ++res; 
        }

        std::string str = s.substr(l + 1, r - l - 1);

        return str;
    }

   public:
    int countSubstrings(string s) {
        if (s.size() == 1) 
            return 1;

        this->s = s;

        for (int i = 0; i < s.size(); i++) {
            helper(i);
            helper(i, i + 1);
        }

        return res;
    }
};
