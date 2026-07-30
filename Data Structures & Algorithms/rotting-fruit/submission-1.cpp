class Solution {
    int m = 0, n = 0;
    
    int bananas = 0;
    int currentBananas = 0;

    std::vector<std::vector<bool>> seen; 
    std::vector<std::vector<int>> pos = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    std::queue<std::pair<int, int>> bfsQueue;

    bool helper(const int& r, const int& c) {
        if(r < 0 || c < 0)
            return false;

        if(r >= m || c >= n)
            return false; 
        
        return true;
    }
public:
    // BFS!!!!
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        seen = vector(m, vector(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    ++bananas;
                }
                else if(grid[i][j] == 2) {
                    bfsQueue.push(std::make_pair(i, j));
                }
            }
        }

        std::cout << "bananas: " << bananas << '\n';
        std::cout << "bfsQueue.size(): " << bfsQueue.size() << '\n';


        int res = 0; 
        while(bfsQueue.size() > 0) {
            int len = bfsQueue.size();
            std::cout << "res: " << res << '\n'; 

            if(bananas == currentBananas)
                break; 

            for(int i = 0; i < len; i++) {
                int r = bfsQueue.front().first, c = bfsQueue.front().second;
                bfsQueue.pop();

                for(const auto& vec : pos) {
                    int row = r + vec[0], col = c + vec[1];

                    if(helper(row, col) && !seen[row][col] && grid[row][col] == 1) {                        
                        ++currentBananas;
                        bfsQueue.push(std::make_pair(row, col));
                        seen[row][col] = true; 

                        std::cout << currentBananas << '\n';
                    }
                }
            }

            ++res; 
        }

        return ((bananas == currentBananas) ? res : -1); 
    }
};
