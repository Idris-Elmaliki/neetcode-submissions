/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {
    private var res : Int = 0
    fun rangeSumBST(root: TreeNode?, low: Int, high: Int): Int {
        dfs(root, low, high)

        return res
    }

    fun dfs(root: TreeNode?, low: Int, high: Int) {
        if(root == null)
            return

        if(root.`val` >= low && root.`val` <= high) {
            res += root.`val`
        }

        dfs(root.left, low, high)
        dfs(root.right, low, high)
    }
}
