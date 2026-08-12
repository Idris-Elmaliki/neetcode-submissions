class Solution {
    bool res = true;

    std::unordered_set<int> seen; 
    std::unordered_map<int, std::vector<int>> graph; 

    void bfs(const int& node) {
        if(seen.find(node) != seen.end()) {
            res = false;
            return; 
        }

        seen.insert(node);
        std::queue<std::pair<int, int>> bfsQueue;
        bfsQueue.push(std::make_pair(node, -1));

        while(bfsQueue.size() > 0) {
            int len = bfsQueue.size();

            for(int i = 0; i < len; i++) {
                int curr = bfsQueue.front().first;
                int parent = bfsQueue.front().second;
                bfsQueue.pop(); 

                for(const auto& neighbor : graph[curr]) {
                    if (neighbor == parent) continue;
                    if(seen.find(neighbor) != seen.end()) {
                        res = false;
                        return; 
                    }

                    seen.insert(neighbor);
                    bfsQueue.push(std::make_pair(neighbor, curr));
                }
            }
        }

    }

public:    
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) 
            return false;
        if (n == 1) 
            return true;

        for(const auto& vec : edges) {
            graph[vec[0]].emplace_back(vec[1]);
            graph[vec[1]].emplace_back(vec[0]);
        }

        bfs(graph.begin()->first);     

        return res && seen.size() == n; 
    }
};
