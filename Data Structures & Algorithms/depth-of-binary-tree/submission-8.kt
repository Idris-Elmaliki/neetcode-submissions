/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */

class Solution {
    fun maxDepth(root: TreeNode?): Int {
        if(root == null) {
            return 0
        }

        val left = 1 + maxDepth(root.left)
        val right = 1 + maxDepth(root.right)

        return max(left, right)
    }
}
