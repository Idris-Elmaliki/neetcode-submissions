class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1; 

        int maxL = 0, maxR = 0; 

        int sum = 0; 
        while(l < r) {
            if(height[l] > maxL) {
                maxL = height[l]; 
            }

            if(height[r] > maxR) {
                maxR = height[r]; 
            }

            if(maxL - height[l] > 0) {
                sum += (maxL - height[l]); 
            }
            else if(maxR - height[r] > 0) {
                sum += (maxR - height[r]); 
            }

            if(maxL < maxR) {
                ++l; 
            }
            else {
                --r; 
            }
        }
        
        return sum; 
    }
};
