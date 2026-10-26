class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;

        std::unordered_map<char, int> freq;

        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            if (freq.find(s[r]) == freq.end()) {
                freq[s[r]] = 1;
            } 
            else {
                freq[s[r]]++;
            }

            while (freq[s[r]] > 1) {
                freq[s[l]]--;

                ++l;
            }

            res = std::max(res, r - l + 1);
        }

        return res;
    }
};
