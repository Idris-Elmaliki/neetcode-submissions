class Solution {
    std::vector<bool> memo; 
    std::vector<bool> seen; 

    std::unordered_set<std::string> stringSet; 
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.size() == 1) {
            if(wordDict.size() > 1) {
                return false; 
            }
            else if(wordDict[0].size() > 1) {
                return false;
            }
            else if(s != wordDict[0].substr(0, 1)) {
                return false; 
            }
        }

        stringSet = unordered_set(wordDict.begin(), wordDict.end()); 
        
        memo = vector(s.size() + 1, false); 
        memo[0] = true; 
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (memo[j] && (stringSet.find(s.substr(j, i - j)) != stringSet.end())) {
                    memo[i] = true;
                    break;
                }
            }
        }
        
        return memo[memo.size() - 1]; 
    }
};
