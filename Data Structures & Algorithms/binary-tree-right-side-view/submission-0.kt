/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */

class Solution {
    fun rightSideView(root: TreeNode?): List<Int> {
        if(root == null)
            return listOf()

        val queue = ArrayDeque<TreeNode>()
        queue.add(root)

        val res = mutableListOf<Int>()

        while(queue.size > 0) {
            val currentSize = queue.size

            for(i in 0 until currentSize) {
                val front = queue.first()
                queue.removeFirst()

                if(i == currentSize - 1) {
                    res.add(front.`val`)
                }

                if(front.left != null) {
                    queue.add(front.left)
                }

                if(front.right != null) {
                    queue.add(front.right)
                }
            }
        }

        return res
    }
}
