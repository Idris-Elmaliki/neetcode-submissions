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
            println("One of the nodes are null!")
            if(p == null && q == null) {
                println("Both of the nodes are null!")
                return true
            }
            else {
                println("Only one of the nodes are null!")
                return false 
            }
        }

        println("p.val = ${p.`val`}, q.val = ${q.`val`}")

        val isEqual = 
            if(p.`val` == q.`val`) { true }
            else { false }

        val left = isSameTree(p.left, q.left)
        val right = isSameTree(p.right, q.right)
        
        return left && right && isEqual
    }
}
