class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char, int> s1Map; 

        for(const auto &c : s1) {
            if(s1Map.find(c) == s1Map.end()) {
                s1Map.insert({c, 1});
            }
            else {
                s1Map[c]++; 
            }
        }

        std::cout << "Map size: " << s1Map.size() << '\n'; 

        int l = 0, r = 0; 

        while(r < s2.size()) {
            if(s1Map.find(s2[r]) == s1Map.end()) {
                ++r; 
            }
            else {
                l = r; 
                int currentStrCount[26] = {};
                while(s1Map.find(s2[r]) != s1Map.end()) 
                {
                    currentStrCount[int(s2[r] - 'a')]++; 
                    
                    if(currentStrCount[int(s2[r] - 'a')] > s1Map[s2[r]]) 
                    {
                        if(s2[l] == s2[r]) 
                        {
                            ++l;
                        }
                        else {
                            break; 
                        }
                    }

                    ++r; 
                }

                if(r - l == s1.size()) {
                    return true;
                }
                else {
                    l = r; 
                }
            }
        }

        return false;
    }
};
