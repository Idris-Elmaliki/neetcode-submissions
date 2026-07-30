class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> total; 

        std::sort(nums.begin(), nums.end());  

        for(int i = 0; i < static_cast<int>(nums.size()); i++) {
            int l = i+1, r = nums.size() - 1;
            
            if(nums[i] > 0)
                break; 
        
            if(i > 0 && nums[i] == nums[i -1])
                continue; 

            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r]; 

                if(sum < 0) {
                    ++l; 
                }
                else if(sum > 0) {
                    --r;
                }
                else {
                    std::vector<int> vec = {nums[i], nums[l], nums[r]};
                    total.emplace_back(vec);

                    ++l; 
                    --r;

                    while(l < r && nums[l] == nums[l-1]) {
                        ++l; 
                    }
                } 
            }
        }

        return total; 
    }
};
