class Solution {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; 
public:
    int connectSticks(vector<int>& sticks) {
        if(sticks.size() == 1)
            return 0; 
        
        minHeap = priority_queue(sticks.begin(), sticks.end(), std::greater<int>());
        
        int res = 0; 
        while(minHeap.size() > 1) {
            int x = minHeap.top();
            minHeap.pop();
            
            int y = minHeap.top();
            minHeap.pop();

            int sum = x + y; 
            minHeap.emplace(sum);
            
            res += sum; 
        }
        
        return res; 
    }
};