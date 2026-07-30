class Solution {
    int m = 0, n = 0;

    vector<vector<int>> pos = {
        {1, 0}, 
        {-1, 0},
        {0, 1}, 
        {0, -1}
    };

    bool helper(const int& r, const int& c) {
        if(r < 0 || c < 0)
            return false;

        if(r >= m || c >= n) 
            return false; 

        return true;         
    }

    void dfs(
        const int& r, 
        const int& c, 
        vector<vector<bool>>& ocean, 
        vector<vector<int>>& heights
    ) {
        ocean[r][c] = true;
        for (const auto& vec : pos) {
            int row = r + vec[0], col = c + vec[1];

            if(helper(row, col) && !ocean[row][col] && heights[row][col] >= heights[r][c]) {
                dfs(row, col, ocean, heights);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();

        vector<vector<bool>> pac = vector(m, vector(n, false));
        vector<vector<bool>> atl = vector(m, vector(n, false));

        for (int c = 0; c < n; ++c) {
            dfs(0, c, pac, heights);
            dfs(m - 1, c, atl, heights);
        }
        for (int r = 0; r < m; ++r) {
            dfs(r, 0, pac, heights);
            dfs(r, n - 1, atl, heights);
        }

        vector<vector<int>> res;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (pac[r][c] && atl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }
};