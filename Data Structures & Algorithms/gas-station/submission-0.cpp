class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;

        int diff = 0, sum = 0;
        for (int i = 0; i < gas.size(); i++) {
            diff += gas[i] - cost[i];

            if (diff < 0) {
                diff = 0;
                start = (i + 1) % gas.size();
            }

            sum += (gas[i] - cost[i]);
        }

        if (sum < 0)
            return -1;

        return start;
    }
};
