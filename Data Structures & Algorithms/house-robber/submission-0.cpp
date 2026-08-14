class Solution {
    std::vector<int> m_nums; 
    std::vector<int> memo; 

    int dp(const int& index) {
        if(index == 0)
            return m_nums[0];

        if(index == 1)
            return std::max(m_nums[1], m_nums[0]);

        if(memo[index] != -1)
            return memo[index]; 

        memo[index] = std::max(dp(index - 1), dp(index - 2) + m_nums[index]); 

        return memo[index]; 
    }

public:
    int rob(vector<int>& nums) {
        m_nums = nums;
        memo = vector(nums.size(), -1); 

        return dp(nums.size() - 1); 
    }
};
