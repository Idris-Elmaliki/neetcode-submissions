class Solution {
    int m = 0, target = 0; 

    std::vector<int> candidates; 

    std::vector<int> current; 
    std::vector<std::vector<int>> res; 

    void backtracking(int i, int total) {
        if(total == target) {
            res.push_back(current); 
            return;
        }

        if(total > target || i >= m) {
            return;
        }

        int jumpTo = i + 1; 
        while (jumpTo < m && candidates[jumpTo] == candidates[i]) {
            ++jumpTo;
        }

        current.emplace_back(candidates[i]);
        backtracking(i + 1, total + candidates[i]);

        current.pop_back();
        backtracking(jumpTo, total);
    }

public:
    vector<vector<int>> combinationSum2(vector<int> candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        
        m = candidates.size();
        this->target = target; 
        this->candidates = candidates; 

        backtracking(0, 0);

        return res; 
    }
};
