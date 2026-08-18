class Solution {
	int n = 0; 

	vector<int> m_nums; 
	vector<vector<int>> memo; 

public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0]; 

            n = nums.size(); 
        m_nums = nums; 

        memo = vector(2, vector(nums.size(), -1)); 
            
        memo[0][0] = 0;
        memo[1][0] = nums[0];
        memo[0][1] = nums[1];
        memo[1][1] = nums[0];

        for(int i = 2; i < n; i++) {
            memo[0][i] = max(memo[0][i-1], memo[0][i-2] + nums[i]); 

            if(i == n - 1) {
                memo[1][i] = memo[1][i-1]; 
            }
            else {
                memo[1][i] = max(memo[1][i-1], memo[1][i-2] + nums[i]);
            }	
        }
            
        return max(memo[0][n-1], memo[1][n-1]); 
    }
};