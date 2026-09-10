class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
      	std::sort(people.begin(), people.end()); 
		
		int res = 0; 

        int l = 0, r = people.size() - 1;
		while (l <= r) {
            if (people[l] + people[r] <= limit) {
                ++l; // lightest person shares the boat
            }
            --r;     // heaviest person always takes a boat
            ++res;
        }

		return res; 
    }
};