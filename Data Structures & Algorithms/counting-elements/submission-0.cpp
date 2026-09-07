class Solution {
public:
    int countElements(vector<int>& arr) {
        std::unordered_map<int, int> intMap; 

        for(const int& n : arr) {
            if(intMap.find(n) == intMap.end()) {
                intMap.insert({n, 1}); 		
            }
            else {
                intMap[n]++; 
            }
        }


        int res = 0; 
        for(const auto& [k, v] : intMap) {
            if(intMap.find(k+1) != intMap.end()) {
                res += intMap[k];
            }
        }

        return res; 
    }
};
