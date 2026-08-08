class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> heap(stones.begin(), stones.end());

        while(heap.size() > 0) {    
            if(heap.size() == 1)
                return heap.top();

            int x = heap.top();
            std::cout << "x: " << x << '\n'; 
            heap.pop();
            
            int y = heap.top(); 
            std::cout << "y: " << y << '\n'; 
            heap.pop();

            if(x > y) {
                x = x - y; 
                heap.emplace(x); 
            }
        }

        return 0; 
    }
};
