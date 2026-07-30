class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
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

        std::vector<int> vec; 

        if(hasZero == true) {
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] == 0) {
                    vec.emplace_back(product);
                }
                else {
                    vec.emplace_back(0); 
                }
            }
        }
        else {
            for(int i = 0; i < nums.size(); i++) {
                int ignoredNum = nums[i]; 

                // need to remove the divide operator!
                vec.emplace_back((product / ignoredNum)); 
            }
        }

        return vec; 
    }
};
