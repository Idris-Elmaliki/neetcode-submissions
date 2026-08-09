class Solution {
    std::priority_queue<int> heap; 
public:
    int findKthLargest(vector<int>& nums, int k) {
        heap = priority_queue(nums.begin(), nums.end());
        
        while(k - 1 > 0) {
            heap.pop();
            --k; 
        }
        
        return heap.top();
    }
};