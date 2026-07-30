class Solution {
public:
    int maxArea(vector<int>& h) {
        int l = 0, r = h.size() - 1; 

        int maxProduct = 0;  
        while(l < r) {
            int currentProduct = 0; 
            int width = (r - l); 

            if(h[l] < h[r]) {
                currentProduct = h[l] * width;  
                ++l; 
            }
            else if(h[l] > h[r]) { 
                currentProduct = h[r] * width; 
                --r;
            }
            else {
                currentProduct = h[l] * width; 
                ++l; 
                --r; 
            }

            if(currentProduct > maxProduct) 
                maxProduct = currentProduct; 
        }

        return maxProduct;
    }
};
