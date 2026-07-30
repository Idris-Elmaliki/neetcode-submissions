class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> vecProduct;

        int product = 1; 
        bool hasZero = false; 
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0 && hasZero == false) {
                hasZero = true;   
            }
            else {
                product *= nums[i];
            }
        } 

        vecProduct.emplace_back(product); 

        std::vector<int> vec; 

        if(hasZero == true) {
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] == 0) {
                    vec.emplace_back(vecProduct[0]);
                }
                else {
                    vec.emplace_back(0); 
                }
            }
        }
        else {
            for(int i = 0; i < nums.size(); i++) {
                int ignoredNum = nums[i]; 

                // need to remove the divide!
                vec.emplace_back((vecProduct[0] / ignoredNum)); 
            }
        }

        return vec; 
    }
};
