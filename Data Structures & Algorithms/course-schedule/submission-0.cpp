class Solution {
    bool res = true; 
    int m = 0, n = 0; 

    std::unordered_set<int> seen; 
    std::unordered_map<int, std::unordered_set<int>> graph; 

    bool dfs(const int& node) {
        if(seen.find(node) != seen.end())
            return false; 


        seen.insert(node);
        for(const auto& neighbor : graph[node]) {
            if(!dfs(neighbor))
                return false;
        }
        seen.erase(node);

        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.empty())
            return true; 

        m = prerequisites.size();
        n = prerequisites[0].size();

        for(int i = 0; i < m; i++) {
            graph[prerequisites[i][1]].insert(prerequisites[i][0]);
        }

        for(int i = 0; i < numCourses; i++) {
            if(!dfs(i)) return false;
        }

        return true;
    }
};

