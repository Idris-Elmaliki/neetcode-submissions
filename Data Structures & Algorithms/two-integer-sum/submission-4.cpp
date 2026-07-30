class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> Map; 

        for(int i = 0; i < n; i++) {
            int diff = target - nums[i];

            if(Map.find(diff) != Map.end())
                return {Map[diff], i}; 

            Map.insert({nums[i], i});  
        }
        return {}; 
    }
};
