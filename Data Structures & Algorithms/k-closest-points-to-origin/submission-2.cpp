class Solution {
    std::priority_queue<
        std::pair<float, std::vector<int>>, 
        std::vector<std::pair<float, std::vector<int>>>, 
        std::greater<std::pair<float, std::vector<int>>>
    > heap; 

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for(const auto& vec : points) {
            float dis = sqrt(
                pow((0 - vec[0]), 2) + pow((0 - vec[1]), 2)
            );
            std::cout << "dis: " << dis << '\n';
            
            heap.emplace(std::make_pair(dis, vec));
        }
            
        std::vector<std::vector<int>> res; 
        res.reserve(k);
        
        while(k > 0) {
            res.emplace_back(heap.top().second);
            heap.pop();
            --k; 
        }
        
        return res; 
    }
};