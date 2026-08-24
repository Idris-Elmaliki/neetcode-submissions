class Solution {  
    // memo, an array that holds the current coins need to make the sum from 0 -> i
    std::vector<int> memo; 
    std::unordered_map<int, int> coinMap; 

    /*
    How the algorithm can work:

        We can check whether or not a coin exists with the difference between memo[i] and amount.
        If said coin exists, we can continue, else we add the current coin.
    
    */ 

public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0; 

        memo = vector(amount + 1, INT_MAX); 
    
        memo[0] = 0; 

        for(int i = 1; i <= amount; i++) {
            for(const int& c : coins) {
                if(i >= c && memo[i-c] != INT_MAX) {
                    memo[i] = std::min(memo[i], memo[i-c] + 1);
                }
            }
        }

        if(memo[amount] == INT_MAX) {
            return -1;
        }
        
        return memo[amount]; 
    }
};
