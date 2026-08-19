class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;  
        
        while(left <= right) {
            int middle = left + (right - left) / 2; 

            int num = nums[middle]; 
            
            if(num > target) {
                right = middle - 1; 
            }
            else if(num < target) {
                left = middle + 1; 
            }
            else {
                return middle;  
            }
        }


        return -1; 
    }
};
