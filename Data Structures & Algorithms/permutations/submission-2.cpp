class Solution {
    std::vector<int> current; 
    std::vector<std::vector<int>> res; 

    std::unordered_set<int> seen; 

    void recursive(const int& index, const vector<int>& nums) {
        if(index == nums.size()) 
            res.push_back(current); 

        for(int i = 0; i < nums.size(); i++) {
            if(seen.find(nums[i]) == seen.end()) {
                current[index] = nums[i]; 
                seen.insert(nums[i]); 

                recursive(index + 1, nums); 

                seen.erase(nums[i]); 
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        current.resize(nums.size()); 

        recursive(0, nums); 
        return res; 
    }
};
