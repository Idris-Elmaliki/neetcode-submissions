/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */

class Solution {
    fun isSameTree(p: TreeNode?, q: TreeNode?): Boolean {
        if(p == null || q == null) {
            if(p == null && q == null) { return true }
            else { return false }
        }

        val isEqual = 
            if(p.`val` == q.`val`) { true }
            else { false }

        val left = isSameTree(p.left, q.left)
        val right = isSameTree(p.right, q.right)
        
        return left && right && isEqual
    }
}
