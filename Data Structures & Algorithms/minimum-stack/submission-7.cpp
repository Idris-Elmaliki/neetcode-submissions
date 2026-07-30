#include <deque>

class MinStack {
    std::deque<int> stackQueue;
    //std::unordered_map<int, int> smallestNums;
    std::vector<int> smallestNums; 
    int min;  

public:
    MinStack() 
    : min(INT_MAX)
    {}
    
    void push(const int& val) {
        if(val <= min) {
            min = val; 
            smallestNums.emplace_back(min); 
        } 

        stackQueue.emplace_back(val); 
    }
    
    void pop() {

        if(stackQueue.size() > 0) {
            if(stackQueue.back() == min) {                
                smallestNums.pop_back(); 
                
                if(!smallestNums.empty()) {
                    min = smallestNums[smallestNums.size() - 1];
                }
                else {
                    min = INT_MAX; 
                }
            }
            
            stackQueue.pop_back(); 
        }
    }
    
    int top() {
        if(stackQueue.size() > 0) {
            return stackQueue.back(); 
        }
        return UINT_MAX; 
    }
    
    int getMin() {
        if(stackQueue.size() > 0) {
            return min; 
        }

        return UINT_MAX;
    }
};
