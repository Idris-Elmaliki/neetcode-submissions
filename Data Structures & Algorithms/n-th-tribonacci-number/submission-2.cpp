class Solution {
public:
    int tribonacci(int n) {
        if(n < 3) {
            if(n == 0)
                return 0; 
            else if(n == 1) 
                return 1; 
            else
                return 1;
        }

        int memo[3] = {0, 1, 1}; 

        int res = 2; 

        for(int i = 3; i < n; i++) {
            memo[0] = memo[1]; 
            memo[1] = memo[2]; 
            memo[2] = res; 

            res = memo[0] + memo[1] + memo[2]; 
        }

        return res; 
    }
};