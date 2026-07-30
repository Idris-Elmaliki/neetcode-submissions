class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> hashMap; 

        for(int i : nums) {
            hashMap[i]++; 

            if(hashMap.at(i) > 1)
                return true; 
        }

        return false; 
    }
};