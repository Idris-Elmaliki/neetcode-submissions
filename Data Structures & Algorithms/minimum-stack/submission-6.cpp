#include <deque>

class MinStack {
    std::deque<int> stackQueue;
    //std::unordered_map<int, int> smallestNums;
    std::vector<int> smallestNums; 
    int min;  

public:
    MinStack() 
    : min(INT_MAX)
    {
        std::cout << "The min stack was created!\n"; 
    }
    
    void push(const int& val) {
        std::cout << "\nCurrently in .push()\n";

        if(val <= min) {
            std::cout << "\tVal: " << val <<  " is smaller than " << min << '\n'; 
            min = val; 
            std::cout << "\tMin is now: " << min << '\n'; 
            smallestNums.emplace_back(min); 
        } else {
            std::cout << "\tVal is not smaller than " << min << '\n'; 
        }

        stackQueue.emplace_back(val); 
        //smallestNums.insert({stackQueue.size() - 1, min});

        std::cout << "\tStack new size: " << stackQueue.size() << '\n'; 
    }
    
    void pop() {
        std::cout << "\nCurrently in .pop()\n"; 

        if(stackQueue.size() > 0) {
            //smallestNums.erase(stackQueue.size() - 1);
            if(stackQueue.back() == min) {
                std::cout << "\tmin got popped!\n";
                
                smallestNums.pop_back(); 
                std::cout << "\tIs smallestNums empty?: " << std::boolalpha << smallestNums.empty() << '\n';
                
                if(!smallestNums.empty()) {
                    std::cout << "\tsmallestNum size is: " << smallestNums.size() << '\n';
                    min = smallestNums[smallestNums.size() - 1];
                }
                else {
                    min = INT_MAX; 
                    std::cout << "\nMin got reset to INT_MAX!\n";
                }

                std::cout << "\tmin is now: " << min << '\n'; 
            }
            
            stackQueue.pop_back(); 

            std::cout << "\tStack new size: " << stackQueue.size() << '\n'; 
        } 
    }
    
    int top() {
        std::cout << "\nCurrently in .top()\n";

        if(stackQueue.size() > 0) {
            std::cout << "\tCurrent top is: " << stackQueue.back() << '\n';
            return stackQueue.back(); 
        }
        return UINT_MAX; 
    }
    
    int getMin() {
        std::cout << "\nCurrently in .getMin()\n";

        if(stackQueue.size() > 0) {
            std::cout << "\tCurrent Min is: " << min << '\n'; 
            return min; 
        }

        return UINT_MAX;
    }
};
