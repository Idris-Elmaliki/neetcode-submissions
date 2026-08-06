class Solution {
    bool res = false; 
    std::string m_word = "";

    std::vector<std::vector<bool>> seen;

    int n = 0, m = 0; 

    std::vector<std::vector<int>> pos = {
        {0,  1},
        {0, -1}, 
        {1,  0}, 
        {-1, 0}
    };

    bool helper(const int& r, const int& c) {
        if(r < 0 || c < 0)
            return false; 
        
        if(r >= n || c >= m)
            return false; 

        return true; 
    }

    void dfs(std::vector<std::vector<char>> board, int r, int c, int index) {
        if(index >= m_word.size()) {
            res = true; 
            return; 
        }

        if(res) return;

        for(const auto& vec : pos) {
            int row = vec[0], col = vec[1]; 

            if(helper(r + row, c + col) && !seen[r + row][c + col]) {
                std::cout << "board[r][c] " << board[r + row][c + col] << '\n';
                
                if(board[r + row][c + col] == m_word[index]) {
                    seen[r + row][c + col] = true; 
                    dfs(board, r + row, c + col, index + 1);
                    
                    seen[r + row][c + col] = false; 
                }
            }
            if(res) return;
        }
    }
public:    
    bool exist(vector<vector<char>>& board, string word) {
        m_word = word;
        if (m_word.empty()) return true;
        
        n = board.size();
        m = board[0].size();

        seen = vector(n, vector(m, false)); 

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    seen[i][j] = true; 
                    if(res) return true;
                    
                    dfs(board, i, j, 1); 
                    seen[i][j] = false; 
                }
            }
        }

        return res; 
    }
};
