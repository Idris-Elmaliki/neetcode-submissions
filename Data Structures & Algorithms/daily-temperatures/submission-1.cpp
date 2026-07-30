class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<std::pair<int, int>> temp; 

        std::vector<int> vec(temperatures.size(), 0); 

        for(int i = 0; i < temperatures.size(); i++) {
            if(!temp.empty()) {
                if(temp.top().first >= temperatures[i]) {
                    temp.push(std::make_pair(temperatures[i], i));
                }
                else {
                    while(!temp.empty()) {
                        std::pair<int, int> current = temp.top(); 

                        if(current.first >= temperatures[i]) 
                            break; 

                        vec[current.second] = i - current.second;
                        temp.pop(); 
                    }

                    temp.push(std::make_pair(temperatures[i], i));
                }
            }
            else {
                temp.push(std::make_pair(temperatures[i], i));
            }
        }

        return vec; 
    }
};
