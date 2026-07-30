/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */

class Solution {
    private var res : Boolean = true

    fun isValidBST(root: TreeNode?): Boolean {
        if(root == null)
            return true

        dfs(root)
        return res
    }

    fun dfs(root : TreeNode?) : Pair<Int, Int>? {
        if(root == null)
            return null

        val left = dfs(root.left)
        val right = dfs(root.right)

        val minNum = left?.first ?: root.`val`
        val maxNum = right?.second ?: root.`val`

        if((left != null && left.second >= root.`val`) || (right != null && right.first <= root.`val`))
            res = false

        return (minNum to maxNum)
    }
}
