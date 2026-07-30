class Solution {
    int m = 0; 
    std::vector<int> current;
    std::vector<std::vector<int>> res; 

    void backTracking(const int& currentIndex, const std::vector<int>& nums) {    
        if(currentIndex >= m) {
            res.emplace_back(current);
            return;
        }

        int nextIndex = currentIndex;
        while(nextIndex < m && nums[nextIndex] == nums[currentIndex])
            ++nextIndex;

        current.emplace_back(nums[currentIndex]);
        backTracking(currentIndex + 1, nums);

        current.pop_back();
        backTracking(nextIndex, nums);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        if(nums.empty())
            return {{}};

        m = nums.size();
        res.clear();
        current.clear();
        backTracking(0, nums);

        return res; 
    }
};