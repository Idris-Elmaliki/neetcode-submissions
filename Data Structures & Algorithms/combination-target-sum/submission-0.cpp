class Solution {
    int m = 0; 
    int target = 0;
    std::vector<std::vector<int>> res; 

    void backTracking(
        const int& i, 
        int total, 
        const std::vector<int>& nums,
        std::vector<int> curr = {}
    ) {
        if(total == this->target) {
            res.push_back(curr); 
            return; 
        }

        if(i >= m || total > this->target)
            return;

        curr.push_back(nums[i]);
        total += nums[i]; 

        backTracking(i, total, nums, curr);

        curr.pop_back();

        total -= nums[i];
        backTracking(i + 1, total, nums, curr);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        this->target = target; 
        m = nums.size();

        backTracking(0, 0, nums);

        return res; 
    }
};
