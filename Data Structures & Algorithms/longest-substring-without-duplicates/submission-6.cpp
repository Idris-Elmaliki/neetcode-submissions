class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
         
        std::unordered_map<char, int> charMap; 

        int currentMax = 0;
        int absoluteMax = 0;    
        while(r < s.size()) {
            if(l == r) {
                currentMax = 1; 
                charMap.insert({s[l], l}); 
                ++r; 
            }
            else if(!charMap.contains(s[r])) {
                ++currentMax; 
                charMap.insert({s[r], r}); 
                ++r; 
            }
            else {
                if(currentMax > absoluteMax)
                    absoluteMax = currentMax; 

                charMap.erase(s[l]);
                currentMax--; 
                ++l;  
            }
        }

        if(currentMax > absoluteMax) 
            absoluteMax = currentMax; 

        return absoluteMax; 
    }
};
