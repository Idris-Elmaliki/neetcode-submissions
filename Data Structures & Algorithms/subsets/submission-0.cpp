class Solution {
    int m = 0; 
    std::vector<int> current;
    std::vector<std::vector<int>> res; 

    void backTracking(const int& currentIndex, const std::vector<int>& nums) {
        if(currentIndex >= m) {
            res.emplace_back(current);
            return;
        }

        current.emplace_back(nums[currentIndex]);
        backTracking(currentIndex + 1, nums);

        current.pop_back();
        backTracking(currentIndex + 1, nums);
    }

public:
    vector<vector<int>> subsets(const vector<int>& nums) {        
        if(nums.empty())
            return {};

        m = nums.size();
        backTracking(0, nums);

        return res; 
    }
};
