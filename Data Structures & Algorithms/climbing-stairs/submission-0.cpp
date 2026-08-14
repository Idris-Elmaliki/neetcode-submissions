class Solution {
    std::vector<int> memo;
    int size; 

    int dp(const int& num) {
        if(num == 1)
            return 1; 
        if(num == 2)
            return 2; 

        if(memo[num] != -1)
            return memo[num]; 

        memo[num] = dp(num - 1) + dp(num - 2); 

        return memo[num]; 
    }

public:
    int climbStairs(int n) {
        size = n; 
        memo = vector(n + 1, -1); 

        return dp(n);
    }
};
