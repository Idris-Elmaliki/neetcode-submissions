class Solution {
    std::vector<int> vec; 

    std::vector<int> current; 
    std::vector<std::vector<int>> res; 

    void backTracking(int index, const int& k) {        
        if(current.size() == k) {
            res.push_back(current);

            return; 
        }

        for(int i = index; i < vec.size(); i++) {
            current.emplace_back(vec[i]);

            backTracking(i + 1, k);

            current.pop_back();
        } 
    }
public:
    vector<vector<int>> combine(int n, int k) {
        for(int i = 1; i <= n; i++) {
            vec.emplace_back(i);
        }
        
        backTracking(0, k);

        return res; 
    }
};