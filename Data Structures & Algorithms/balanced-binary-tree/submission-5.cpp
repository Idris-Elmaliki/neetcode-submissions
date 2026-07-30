/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    std::pair<bool, int> getLengths(TreeNode* root) {
        if(root == nullptr) {
            return std::make_pair(true, 0); 
        }

        std::pair<bool, int> left = getLengths(root->left); 
        std::pair<bool, int> right = getLengths(root->right); 

        bool balanced = false; 

        if(left.first && right.first && abs(left.second - right.second) <= 1) {
            balanced = true; 
        }

        return std::make_pair(balanced, 1 + std::max(left.second, right.second));  
    }

    bool isBalanced(TreeNode* root) {
        return getLengths(root).first == true; 
    }
};
