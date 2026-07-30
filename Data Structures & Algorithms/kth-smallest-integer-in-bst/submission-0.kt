/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */

class Solution {
    private var res : Int = 0
    private var currentK = 0
    fun kthSmallest(root: TreeNode?, k: Int): Int {
        dfs(root, k)
        return res
    }

    fun dfs(root: TreeNode?, k: Int) {
        if(root == null)
            return 

        dfs(root.left, k)

        currentK += 1
        if(currentK == k)
            res = root.`val`

        dfs(root.right, k)
    }
}
