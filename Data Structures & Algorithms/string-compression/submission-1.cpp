class Solution {
    // We will have a vector of chars, it can contain 1 or more groups of consecutive chars
    // It looks like we are guaranteed consecutivity, so something like: [a, a, b, a] wouldn’t exist
    // We also aren’t guaranteed that there will be a group, we can simply just have an if statement
    // that checks if the vec size is 0!

    // The best logic for this would be a sliding windows approach, as this will allow two things
    // for us:
    // 1. We are able to see the actual difference between l & r
    // 2. Doing a sliding window approach ensures that we can also do the same logic for any other
    // consecutive chars in the vec

public:
    int compress(vector<char>& chars) {
        if (chars.size() == 0)
            return 0;
        else if (chars.size() == 1)
            return 1;

        int l = 0, current = 0;
        for (int r = 0; r <= chars.size(); r++) {
            if (r == chars.size() || chars[l] != chars[r]) {
                chars[current++] = chars[l];
                int diff = r - l;

                if (diff > 1) {
                    string countStr = to_string(diff);
                    for (char c : countStr) {
                        chars[current++] = c;
                    }
                }

                l = r;
            }
        }

        return current;
    }
};
