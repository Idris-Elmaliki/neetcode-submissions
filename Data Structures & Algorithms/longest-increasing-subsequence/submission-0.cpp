class Solution {
    std::vector<int> m_nums; 
    std::vector<int> memo; 

    int dp(const int& index) {
        if(memo[index] != -1)
            return memo[index]; 

        int res = 1; 

        for(int i = 0; i < index; i++) {
            if(m_nums[index] > m_nums[i])
                res = std::max(res, dp(i) + 1); 
        }

        memo[index] = res; 

        return memo[index]; 
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        m_nums = nums; 

        memo = vector(nums.size(), -1); 

        int res = 0; 
        for(int i = 0; i < nums.size(); i++) {
            res = std::max(res, dp(i)); 
        }

        return res; 
    }
};
