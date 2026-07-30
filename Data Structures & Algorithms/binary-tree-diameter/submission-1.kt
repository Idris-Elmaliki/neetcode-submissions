/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */

class Solution {
    private var maxDiameter = 0

    fun diameterOfBinaryTree(root: TreeNode?): Int {
        height(root)
        return maxDiameter
    }

    private fun height(root: TreeNode?): Int {
        if (root == null)
            return 0
        
        val l = height(root.left)
        val r = height(root.right)

        maxDiameter = max(maxDiameter, l + r)
        
        return 1 + max(l, r)
    }
}
