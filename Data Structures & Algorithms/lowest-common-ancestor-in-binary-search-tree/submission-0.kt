/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */

class Solution {
    fun lowestCommonAncestor(
        root: TreeNode?, 
        p: TreeNode?, 
        q: TreeNode?
    ): TreeNode? {
        if(root == null)
            return null

        if(root.`val` == p?.`val` || root.`val` == q?.`val`) {
            return root 
        }

        val left = lowestCommonAncestor(root.left, p, q)
        val right = lowestCommonAncestor(root.right, p, q)

        if(left != null && right != null) {
            return root
        }

        if(left != null) {
            return left
        }

        return right
    }
}
