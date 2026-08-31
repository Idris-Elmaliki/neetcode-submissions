class Solution {
    std::vector<bool> memo; 

    // what should memo store?

    // We can either store ints (as in the current sum)
    // or we store booleans 

    // I think int would be better as we want to track the current 

public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() == 1) {
            if(nums[0] % 2 == 1); 
                return false; 

            return true;  
        }
        
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        if(sum % 2 == 1)
            return false; 

        memo = vector(sum/2 + 1, false);

        memo[0] = true; 
        for(int i = 0; i < nums.size(); i++) {
            for(int j = sum/2; j >= nums[i]; j--) {
                if(memo[j - nums[i]]) {
                    memo[j] = true; 
                }
            }
        }

        return memo[memo.size() - 1]; 
    }  
};
