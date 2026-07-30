class Solution {
    int res = 0; 
    int currentIslandSize = 0; 
    vector<vector<bool>> seen;
    vector<vector<int>> pos = {
    //   x  y
        {0, 1}, 
        {0, -1},
        {1, 0}, 
        {-1, 0}
    }; 

    int m = 0, n = 0;

    bool helper(const int& row, const int& col) {
        if(row == -1 || col == -1)
            return false; 
        
        if(row >= m || col >= n) 
            return false; 
        
        return true; 
    }

    void dfs(const int& row, const int& col, vector<vector<int>>& grid) {
        if(helper(row, col) && !seen[row][col] && grid[row][col] == 1) {
            ++currentIslandSize; 
            seen[row][col] = true; 

            for(const auto& vec : pos) {
                dfs(row + vec[0], col + vec[1], grid);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        seen = vector(m, vector(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!seen[i][j] && grid[i][j] == 1) {
                    dfs(i, j, grid);
                }

                res = std::max(res, currentIslandSize);
                currentIslandSize = 0; 
            }
        }
        
        return res; 
    }
};
