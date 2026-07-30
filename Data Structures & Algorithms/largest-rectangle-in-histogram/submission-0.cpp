class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<std::pair<int, int>> rec; 

        int maxArea = 0; 
        for(int i = 0; i < heights.size(); i++) {
            if(rec.empty()) {
                rec.push(std::make_pair(heights[i], i)); 
            }   
            else {
                int index = i; 
                while(!rec.empty() && heights[i] < rec.top().first) {
                    int currentArea = rec.top().first * (i - rec.top().second);

                    if(currentArea > maxArea)
                        maxArea = currentArea; 
                    
                    index = rec.top().second; 

                    rec.pop();
                }

                rec.push(std::make_pair(heights[i], index));
            }
        }

        if(!rec.empty()) {
            while(!rec.empty()) {
                int currentArea = rec.top().first * (heights.size() - rec.top().second);

                if(currentArea > maxArea)
                    maxArea = currentArea; 

                rec.pop();
            }
        }

        return maxArea; 
    }
};
