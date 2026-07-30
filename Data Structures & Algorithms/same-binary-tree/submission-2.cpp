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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr)
            return true;

        std::queue<TreeNode*> pQueue;
        std::queue<TreeNode*> qQueue; 

        pQueue.push(p); 
        qQueue.push(q); 

        while(pQueue.size() > 0 && qQueue.size() > 0) {
            TreeNode* pCurrent = pQueue.front(); 
            TreeNode* qCurrent = qQueue.front(); 

            pQueue.pop(), qQueue.pop();

            if(pCurrent == nullptr || qCurrent == nullptr) {
                if(pCurrent != qCurrent)
                    return false; 
            }
            else {
                if(pCurrent->val != qCurrent->val) {
                    return false; 
                }
            }

            if(pCurrent != nullptr) {
                pQueue.push(pCurrent->left);
                pQueue.push(pCurrent->right);
            }

            if(qCurrent != nullptr) {
                qQueue.push(qCurrent->left);
                qQueue.push(qCurrent->right);
            }
        }

        return true; 
    }
};
