class Solution {
    int maxPos = 0, maxNega = 0; 
    int maxLeft = 0, maxRight = 0; 

public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0]; 
        }

        for(const int& num : nums) {
            if(num == 0) {
                int currentMax = std::max(maxPos, maxNega);
                maxLeft = std::max(maxLeft, currentMax); 

                maxPos = 0; 
                maxNega = 0; 

                continue; 
            }

            if(maxPos == 0) {
                if(num > 0) {
                    maxPos = num; 
                }
            }
            else {
                if(num > 0) {
                    maxPos *= num; 
                }
                else {
                    maxLeft = std::max(maxLeft, maxPos); 
                    maxPos = 0; 
                }
            }

            if(maxNega == 0) {
                maxNega = num; 
            }
            else {
                maxNega *= num; 
            }

            int currentMax = std::max(maxPos, maxNega);
            maxLeft = std::max(maxLeft, currentMax); 
        }

        maxPos = 0, maxNega = 0;

        for(auto it = nums.rbegin(); it != nums.rend(); ++it) {
            int num = *it; 

            if(num == 0) {
                int currentMax = std::max(maxPos, maxNega);
                maxRight = std::max(maxRight, currentMax); 

                maxPos = 0; 
                maxNega = 0; 

                continue; 
            }

            if(maxPos == 0) {
                if(num > 0) {
                    maxPos = num; 
                }
            }
            else {
                if(num > 0) {
                    maxPos *= num; 
                }
                else {
                    maxRight = std::max(maxRight, maxPos); 
                    maxPos = 0; 
                }
            }

            if(maxNega == 0) {
                maxNega = num; 
            }
            else {
                maxNega *= num; 
            }

            int currentMax = std::max(maxPos, maxNega);
            maxRight = std::max(maxRight, currentMax); 
        }

        return std::max(maxLeft, maxRight); 
    }
};
