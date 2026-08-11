class Solution {
    int res = 0; 

    std::unordered_map<int, std::vector<int>> graph;
    std::unordered_set<int> seen; 

    void dfs(const int& node) {
        if(seen.find(node) != seen.end()) {
            return;
        }

        seen.insert(node);
        std::vector<int> vec = graph[node]; 
        
        for(int i = 0; i < vec.size(); i++) {
            dfs(vec[i]); 
        }
    } 

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        for(const auto& vec : edges) {

            graph[vec[0]].emplace_back(vec[1]); 
            graph[vec[1]].emplace_back(vec[0]); 
        }
        for(int i = 0; i < n; i++) { 
            if(seen.find(i) == seen.end()) {
                ++res; 
                dfs(i);
            }     
        }

        return res; 
    }
};
