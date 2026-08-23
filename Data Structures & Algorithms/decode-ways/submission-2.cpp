class Solution {
    std::unordered_map<std::string, char> charMap; 
    std::vector<int> memo; 

// memo: an array that stores the current max converted string from 0 -> i
// We need to see the past

// We also need to worry about a leading zero, we can have a set that stores all the 
// indexes that have a zero so we know to skip it once we do the conversion logic

public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') 
            return 0;
            
        if(s.size() == 1) {
            return 1;
        }

        for(int i = 0; i < 26; i++) {
            charMap.insert({std::to_string(i + 1), 'A' + i}); 
        }

        memo.resize(s.size() + 1); 

        memo[0] = 1; 
        memo[1] = 1; 

        for(int i = 2; i <= s.size(); i++) {
           
            int single = s[i-1] - '0';
            int doubleD = stoi(s.substr(i-2, 2));

            if (single >= 1) {
                memo[i] += memo[i-1];
            }
            if (doubleD >= 10 && doubleD <= 26) {
                memo[i] += memo[i-2];
            }
        }

        return memo[memo.size() - 1]; 
    }
};
