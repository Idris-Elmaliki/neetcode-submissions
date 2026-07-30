class Solution {
public:
    bool isValid(string s) {
        std::stack<char> pStack;  
        std::unordered_map<char, char> _map = {
            {'}', '{'}, 
            {')', '('}, 
            {']', '['}
        }; 

        for(int i = 0; i < s.size(); i++) {
            if(_map.count(s[i])) {
                if(!pStack.empty() && pStack.top() == _map[s[i]]) {
                    pStack.pop(); 
                }
                else {
                    return false; 
                }
            }
            else {
                pStack.push(s[i]); 
            }
        }

        return pStack.empty(); 
    }
};
