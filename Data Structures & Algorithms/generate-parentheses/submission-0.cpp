class Solution {
    int size = 0; 
    std::string current = "";
    std::vector<std::string> res; 


    void backTracking(int open, int closed) {
        if(open == size && closed == size) {
            res.push_back(current);
            return;
        }
            
        if(open < size) {
            current += "(";
            backTracking(open + 1, closed);
            current.pop_back(); 
        }

        if(closed < open) {
            current += ")";
            backTracking(open, closed + 1);
            current.pop_back(); 
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        if(n == 1)
            return {"()"};
        
        size = n; 
        backTracking(0, 0); 

        return res; 
    }
};
