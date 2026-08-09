class KthLargest {
    int index = 0; 
    std::priority_queue<int> heap; 
public:
    KthLargest(int k, vector<int>& nums)
    : index(k), heap(nums.begin(), nums.end()) 
    { }
    
    int add(int val) {
        heap.emplace(val);

        int i = index;

        std::vector<int> vec;
        vec.reserve(index); 
         
        while(i > 1) {
            vec.emplace_back(heap.top());
            heap.pop(); 

            --i; 
        } 

        int kthNum = heap.top();

        for(const auto& num : vec)
            heap.emplace(num);

        return kthNum; 
    }
};
