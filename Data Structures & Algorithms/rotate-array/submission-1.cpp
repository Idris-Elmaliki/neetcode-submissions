class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		if(k % nums.size() == 0)	
			return; 

		std::vector<int> res;
		int neededRotations = k % nums.size();
		int start = nums.size() - neededRotations;
		
		int r = start;

		while(neededRotations > 0) {
			res.emplace_back(nums[r]); 
			r = (r + 1) % nums.size(); 
			--neededRotations; 
		}
		
		while(res.size() < nums.size()) {
			res.emplace_back(nums[r]); 
			r = (r + 1) % nums.size();
		}

		
 		nums = res; 
    }
};