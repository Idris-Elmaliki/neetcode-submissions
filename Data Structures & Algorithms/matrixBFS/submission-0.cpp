class Solution {
    int m = 0, n = 0; 
    std::vector<std::vector<bool>> seen; 
    std::queue<std::pair<int, int>> bfsQueue; 
    std::vector<std::vector<int>> pos = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    int res = 0; 

    bool helper(const int& r, const int& c) {
        if(r < 0 || c < 0)
            return false;

        if(r >= m || c >= n)
            return false; 

        return true; 
    }
public:
    int shortestPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        seen = vector(m, vector(n, false));

        bfsQueue.push(std::make_pair(0, 0));

        while(bfsQueue.size() > 0) {
            int len = bfsQueue.size();

            for(int i = 0; i < len; i++) {
                int row = bfsQueue.front().first;
                int col = bfsQueue.front().second;
                bfsQueue.pop();

                if(row == m - 1 && col == n - 1)
                    return res;

                for(const auto& vec : pos) {
                    if(helper(row + vec[0], col + vec[1]) && !seen[row + vec[0]][col + vec[1]]) {
                        if(grid[row + vec[0]][col + vec[1]] == 1)
                            continue;
                        
                        bfsQueue.push(std::make_pair(row + vec[0], col + vec[1]));
                        seen[row + vec[0]][col + vec[1]] = true;
                    }
                }
            }
            ++res; 
        }

        return -1;
    }
};
