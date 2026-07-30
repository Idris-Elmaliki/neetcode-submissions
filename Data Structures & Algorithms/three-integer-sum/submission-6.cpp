class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> vec2;

        std::sort(nums.begin(), nums.end()); 

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0)
                break; 
            
            if(i > 0 && nums[i] == nums[i-1])
                continue; 

            int l = i+1, r = nums.size() - 1;
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
                    vec2.emplace_back(vec);

                    ++l; 
                    --r;
                    while(l < r && nums[l] == nums[l-1]) {
                        ++l; 
                    }
                } 
            } 
        }

        return vec2;
    }
};
