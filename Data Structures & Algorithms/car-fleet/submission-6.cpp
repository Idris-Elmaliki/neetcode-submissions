class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int, int>> vec; 
        vec.reserve(position.size());

        for(int i = 0; i < position.size(); i++) {
            vec.emplace_back(std::make_pair(position[i], speed[i]));
        }
        
        std::sort(vec.rbegin(), vec.rend()); 


        std::stack<float> carFleets; 
        
        for(int i = 0; i < vec.size(); i++) {
            float time = (float)(target - vec[i].first) / vec[i].second;

            if(carFleets.empty()) {
                carFleets.push(time);
            }
            else if(carFleets.top() >= time) {
                continue;
            }
            else {
                carFleets.push(time); 
            }
        }

        return carFleets.size(); 
    }
};
