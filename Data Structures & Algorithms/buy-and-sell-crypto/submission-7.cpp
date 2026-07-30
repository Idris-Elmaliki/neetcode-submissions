class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0; 
        int r = 0; 

        int maxProfit = 0; 
        while(r < prices.size()) {
            if(prices[r] - prices[l] <= 0) {
                l = r; 
            }

            int currentProfit = prices[r] - prices[l]; 

            if(currentProfit > maxProfit) {
                maxProfit = currentProfit; 
            }

            ++r; 
        }

        return maxProfit; 
    }
};
