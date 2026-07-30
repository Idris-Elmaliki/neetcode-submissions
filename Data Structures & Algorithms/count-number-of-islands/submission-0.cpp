class Solution {
    int m;
    int n;
    std::vector<std::vector<char>> grid;
    std::vector<std::vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    std::vector<std::vector<bool>> seen;

    void dfs(int row, int col) {
        for(std::vector<int>& direction: directions) {

            int nextRow = row + direction[0], nextCol = col + direction[1];
            if (valid(nextRow, nextCol) && !seen[nextRow][nextCol]) {
                seen[nextRow][nextCol] = true;
                dfs(nextRow, nextCol);
            }
        }
    }
    
    bool valid(int row, int col) {
        return 0 <= row && row < m && 0 <= col && col < n && grid[row][col] == '1';
    }
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        seen = vector(m, std::vector<bool>(n, false));
        
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !seen[i][j]) {
                    ans++;
                    seen[i][j] = true;
                    dfs(i, j);
                }
            }
        }
        
        return ans;
    }
};
