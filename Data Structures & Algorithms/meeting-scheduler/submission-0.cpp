class Solution {
public:
	// We have three things, vectors of slots one, vectors of slots2 and a duration amount that should be able to fit with the duration 


	// We are trying to find a time that fits for both users based on the allocated time needed (defined by duration) 


	// We can have a two pointer implementation and move each pointer based on start1 > end2 and start2 > end1!


	// If one of these fail then we will move the two pointers, else we will check whether we have allocated time for it


	// We just need to check if the starts are around the same time and whether and if we indeed do have time allocated (end - start >= duration)


// The difficult issue is how we can check if starts are in the same range. I think defining it like that is a bit weak. A better way to define it is by ensuring again with start1 > end2 or start2 > end1!


// Now how should we pass our result? Simple, take the later earlier time for the start then add it by the duration for the end!


    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        if(slots1.empty() || slots2.empty())
                return {}; 
            
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());

        int l = 0, r = 0; 
        
        while(l < slots1.size() && r < slots2.size()) {
            int start1 = slots1[l][0], end1 = slots1[l][1]; 
            int start2 = slots2[r][0], end2 = slots2[r][1]; 
            
            int start = std::max(start1, start2);
            int end = std::min(end1, end2);

            if(end - start >= duration) {
                return {start, start + duration};
            }

            if(end1 < end2) {
                ++l;
            } else {
                ++r;
            }
        }
    
        return {}; 
    }
};
