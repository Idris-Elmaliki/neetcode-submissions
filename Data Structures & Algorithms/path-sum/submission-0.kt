/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */

class Solution {
    private var target : Int = 0

    fun hasPathSum(root: TreeNode?, targetSum: Int): Boolean {
        target = targetSum
        return dfs(root, 0)
    }

    fun dfs(root: TreeNode?, currentSum: Int): Boolean {
        if(root == null) {
            return false
        }

        if(root.left == null && root.right == null) {
            return (root.`val` + currentSum) == this.target
        }

        val curr = currentSum + root.`val`

        val left = dfs(root.left, curr)
        val right = dfs(root.right, curr)

        return left || right
    }  
}
