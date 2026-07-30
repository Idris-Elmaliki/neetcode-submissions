class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> mathStack;

        for(int i = 0; i < tokens.size(); i++) { 
            std::string current = ""; 
            bool operatorFound = false; 

            for(auto c : tokens[i]) {
                if(std::isdigit(c)) {
                    current += c;
                }
                else if(tokens[i].size() == 1) {
                    operatorFound = true;
                }
            }

            if(!operatorFound) {
                mathStack.push(std::stoi(tokens[i]));
            }
            else {
                char op = tokens[i][0];
                int result = 0; 

                int f = mathStack.top(); 
                mathStack.pop();

                int s = mathStack.top(); 
                mathStack.pop(); 

                switch(op) {
                    case '*':
                        result = s * f; 
                        break; 
                    case '/':
                        result = s / f; 
                        break;
                    case '+':
                        result = s + f; 
                        break;    
                    case '-':
                        result = s - f; 
                        break;
                }
                mathStack.push(result); 
            }
        }

        return mathStack.top(); 
    }
};
