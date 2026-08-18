class Solution {
    std::unordered_map<int, std::vector<int>> graph;
    std::unordered_set<int> seen;
    std::unordered_set<int> visited;  

    std::vector<int> res; 
    bool isImpossible = false; 

    void dfs(const int& node) {
        if(seen.find(node) != seen.end()) {
            isImpossible = true; 
            return;
        }
        if(visited.find(node) != visited.end() || isImpossible)
            return; 
        
        seen.insert(node);
        visited.insert(node);
        for(const auto& i : graph[node]) {
            dfs(i); 

            if(isImpossible)
                return; 
        }
        seen.erase(node);
        res.push_back(node);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        for(const auto& vec : prerequisites) {
            graph[vec[0]].emplace_back(vec[1]);
        }

        for(int i = 0; i < numCourses; i++) {
            if(!isImpossible && visited.find(i) == visited.end()) {
                dfs(i);
            }

            if(isImpossible)
                return {};
        }

        return res; 
    }
};
