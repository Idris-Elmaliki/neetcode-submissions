class Solution {
    std::vector<int> m_cost;
    std::vector<int> memo;

    int dp(const int& i) {
        if(i <= 1)
           return 0;

        if(memo[i] != -1)
           return memo[i];
        
        memo[i] = std::min(
            (m_cost[i-1] + dp(i-1)),
            (m_cost[i-2] + dp(i-2))
        );

        return memo[i];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        m_cost = cost;

        memo = vector(cost.size()+1, -1);

        return dp(cost.size());
    }
};
