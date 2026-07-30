class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1; 

        int dP = l + ((r - l) / 2); 

        while(dP < nums.size()) {
            if(nums[dP - 1] < nums[dP + 1]) {
                ++dP; 
            }
            else {
                break; 
            }
        }
        std::cout << "dP: " << dP << '\n'; 


        r = dP; 
        while(l <= r) {
            int m = l + ((r - l) / 2);

            if(nums[m] > target) {
                --r; 
            }
            else if(nums[m] < target) {
                ++l; 
            }
            else {
                std::cout << "First check\n";
                return m; 
            }
        }

        l = dP, r = nums.size() - 1;

        while(l <= r) {
            int m = l + ((r - l) / 2);

            if(nums[m] > target) {
                --r; 
            }
            else if(nums[m] < target) {
                ++l; 
            }
            else {
                std::cout << "Second check\n";
                return m; 
            }
        }

        return -1; 
    }
};
