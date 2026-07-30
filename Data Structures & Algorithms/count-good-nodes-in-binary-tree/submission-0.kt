/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */

class Solution {
    fun goodNodes(root: TreeNode?): Int {
        val num = root?.`val` ?: 0

        return dfs(root, num)
    }

    private fun dfs(root: TreeNode?, maxSoFar : Int) : Int {
        if(root == null)
            return 0

        val isGreater = if(root.`val` >= maxSoFar) { 1 }
        else { 0 }

        val newMax = max(maxSoFar, root.`val`)

        val left = dfs(root.left, newMax)
        val right = dfs(root.right, newMax)

        return isGreater + left + right
    }
}
