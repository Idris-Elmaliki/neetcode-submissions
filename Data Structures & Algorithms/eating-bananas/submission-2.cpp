class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) { 
        int max = 0; 

        for(int i = 0; i < piles.size(); i++) {
            max = std::max(max, piles[i]);
        }

        int l = 1, r = max; 

        int res = max;
        while(l <= r) {
            int m = l + ((r - l) / 2);

            long long time = 0; 
            for (const auto& p : piles) {
                time += (p + m - 1LL) / m; // banana calculations
            }
            if(time <= h) {
                res = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }

        return res; 
    }

};