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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr)
            return {};

        std::vector<int> res;

        std::queue<TreeNode*> rootQueue;
        rootQueue.push(root);

        while(rootQueue.size() > 0) {
            int size = rootQueue.size();

            for(int i = 0; i < size; i++) {
                TreeNode* front = rootQueue.front();
                rootQueue.pop();

                if(i == size - 1) {
                    res.emplace_back(front->val);
                }

                if(front->left != nullptr) 
                    rootQueue.push(front->left);

                if(front->right != nullptr)
                    rootQueue.push(front->right);
            }
        }

        return res; 
    }
};
