class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int r = 0, c = n - 1;

        while (r < matrix.size() && c >= 0) {
            if (matrix[r][c] > target) {
                c--;
            } 
            else if (matrix[r][c] < target) {
                r++;
            } 
            else {
                return true;
            }
        }

        return false;
    }
};
