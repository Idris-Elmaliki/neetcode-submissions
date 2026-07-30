class Solution {
public:
    bool isValid(string s) {
        std::stack<char> pStack;  
        std::unordered_map<char, char> charMap = {
            {'}', '{'}, 
            {')', '('}, 
            {']', '['}
        }; 

        for(int i = 0; i < s.size(); i++) {
            if(charMap.count(s[i])) {
                if(!pStack.empty() && pStack.top() == charMap[s[i]]) {
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
