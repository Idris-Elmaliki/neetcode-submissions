class Solution {
    std::unordered_map<int, std::string> stringMap; 

public:

    std::string encode(std::vector<string>& strs) {
        std::string str = ""; 
        
        for(int i = 0; i < strs.size(); i++) {
            stringMap.insert({i, strs[i]});

            str += strs[i];
        }

        return str; 
    }

    std::vector<std::string> decode(std::string s) {
        std::vector<std::string> vec;
        vec.reserve(stringMap.size()); 

        for(int i = 0; i < stringMap.size(); i++) {
            vec.emplace_back(stringMap[i]); 
        }

        return vec; 
    }
};
