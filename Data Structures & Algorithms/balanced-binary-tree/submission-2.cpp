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
    int getLengths(TreeNode* root) {
        if(root == nullptr) {
            return 0; 
        }

        int left = 1 + getLengths(root->left); 
        int right = 1 + getLengths(root->right); 

        if(abs(left - right) > 1) {
            return -1; 
        }

        return std::max(left, right);  
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true; 

        bool l = isBalanced(root->left); 

        int left = getLengths(root->left); 
        int right = getLengths(root->right); 

        if(left == -1 || right == -1)
            return false; 

        if(abs(left - right) > 1)
            return false;

        bool r = isBalanced(root->right);

        if(l != r)
            return false; 

        return true; 
    }
};
