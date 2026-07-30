class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1; 

        while(l < r) {
            int m = l + (r - l) / 2; 

            std::cout << "Entered the loop\n"; 
            std::cout << "left: " << l << '\n'; 
            std::cout << "right: " << r << '\n';

            if(nums[m] > nums[r]) {
                l = m + 1; 
            }
            else {
                r = m; 
            }

            std::cout << "\nNew values:\n";

            std::cout << "left: " << l << '\n'; 
            std::cout << "right: " << r << '\n';
            std::cout << "middle: " << m << "\n\n";
        }

        return nums[l];
    }
};
