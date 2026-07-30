class Solution {
    std::vector<std::vector<int>> res;

    void backTrack(std::vector<int>& perm, std::vector<int>& nums, std::vector<bool>& pick) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!pick[i]) {
                perm.push_back(nums[i]);
                pick[i] = true;

                backTrack(perm, nums, pick);
                perm.pop_back();

                pick[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> pick(nums.size(), false);
        vector<int> perm;
        backTrack(perm, nums, pick);
        return res;
    }
};