class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> map; 
        
        for(auto i : nums) {
            if(map.find(i) != map.end()) {
                ++map[i]; 
            }
            else {
                map[i] = 1; 
            }
        }

        std::vector<int> vec;
        vec.reserve(k); 

        for(int i = 0; i < k; i++) {
            int key, largestNum = 0; 
            for(const auto& [currentKey, value] : map) {
                if(value > largestNum) {
                    key = currentKey;
                    largestNum = value; 
                }
            }

            vec.emplace_back(key);
            map.erase(key); 
        }

        return vec; 
    }
};
