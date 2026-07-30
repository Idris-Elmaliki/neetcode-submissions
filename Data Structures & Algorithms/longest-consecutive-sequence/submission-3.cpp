class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::map<int, bool> map; 

        for(int i = 0; i < nums.size(); i++) {
            if(map.find(nums[i]) == map.end()) {
                map.insert({nums[i], true}); 
            }
        }

        int longest = 0; 
        int i = -1; 
        std::vector<int> vec; 
        vec.reserve(map.size()); 

        for(const auto& [key, value]: map) {
            std::cout << "Key: " << key << "\n"; 
            std::cout << "\tValue of i: " << i << '\n'; 
            if(vec.empty()) {
                vec.emplace_back(key); 
                ++i; 

                std::cout << "\tValue of i (After): " << i << '\n';
                std::cout << "\tValue of vec: " << vec[i] << "\n\n"; 
            }
            else {
                if(vec[i] + 1 == key) {
                    std::cout << "\tValue of vec (Before): " << vec[i] << '\n';
                    vec.emplace_back(key); 
                    ++i; 

                    std::cout << "\tValue of i (After): " << i << '\n';
                    std::cout << "\tValue of vec (After): " << vec[i] << "\n\n";
                }
                else {
                    if(vec.size() > longest) {
                        longest = vec.size(); 
                    }
                    vec.clear(); 
                    
                    vec.emplace_back(key); 
                    i = 0; 
                }
            }
        }

        if(vec.size() > longest) {
            longest = vec.size(); 
        }


        return longest;
    }
};
