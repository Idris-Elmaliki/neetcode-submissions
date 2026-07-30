class Solution {
    int m = 0, n = 0; 
    const int inf = INT_MAX; 

    std::vector<std::vector<bool>> seen;
    std::queue<std::pair<int, int>> bfsQueue;
    std::vector<std::vector<int>> pos = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    bool helper(const int& r, const int& c) {
        if(r < 0 || c < 0)
            return false; 

        if(r >= m || c >= n)
            return false;

        return true; 
    }

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        seen = vector(m, vector(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    bfsQueue.push(std::make_pair(i, j));
                }
            }
        }

        int res = 0; 
        while(bfsQueue.size() > 0) {
            int len = bfsQueue.size();

            for(int i = 0; i < len; i++) {
                int r = bfsQueue.front().first, c = bfsQueue.front().second;
                
                bfsQueue.pop();

                for(const auto& vec : pos) {
                    int row = r + vec[0], col = c + vec[1];

                    if(helper(row, col) && !seen[row][col]) {
                        seen[row][col] = true; 

                        if(grid[row][col] == inf) {
                            bfsQueue.push(std::make_pair(row, col));
                            grid[row][col] = std::min(res + 1, grid[row][col]);
                        }
                    }
                }
            }
            ++res;
        }
    }
};
