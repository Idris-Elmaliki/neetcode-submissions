class Solution {
   public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0, limit = 0;

        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            limit = (nums[r] == 0) ? limit + 1 : limit;

            while (limit > k) {
                if (nums[l] == 0) --limit;

                ++l;
            }

            res = std::max(res, r - l + 1);
        }

        return res;
    }
};