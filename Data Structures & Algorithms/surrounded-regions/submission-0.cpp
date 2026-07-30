class Solution {
    int m = 0, n = 0; 

    std::vector<std::vector<bool>> seen; 
    std::vector<std::vector<int>> pos = {
        {0,  1},
        {0, -1},
        {1,  0},
        {-1, 0}
    };

    bool helper(const int& r, const int& c) {
        if(r < 0 || c < 0)
            return false;

        if(r >= m || c >= n)
            return false;

        return true;  
    }

    bool helper2(const int& r, const int& c) {
        std::cout << "r: " << r << " c: " << c << '\n';
        if ((c != 0 && c != n - 1) && (r != 0 && r != m - 1))
            return false; 
        
        return true; 
    }
    
    void dfs(const int& r, const int& c, vector<vector<char>>& board) {
        if(helper(r, c) && !seen[r][c] && board[r][c] == 'O') {
            std::cout << " board[r][c] before: " <<  board[r][c] << '\n';
            seen[r][c] = true; 
            board[r][c] = '#';

            std::cout << " board[r][c] after: " <<  board[r][c] << '\n';
            
            for(const auto& vec : pos) {
                dfs(r + vec[0], c + vec[1], board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        seen = vector(m, vector(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O' && !seen[i][j] && helper2(i , j)) {
                    dfs(i, j, board);
                    seen[i][j] = true; 
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '#')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};
