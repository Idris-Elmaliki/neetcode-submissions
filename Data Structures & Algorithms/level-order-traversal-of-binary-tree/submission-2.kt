/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */

class Solution {
    fun levelOrder(root: TreeNode?): List<List<Int>> {
        var res : MutableList<List<Int>> = mutableListOf()

        if(root == null)
            return res

        var queue = ArrayDeque<TreeNode>()
        
        queue.add(root)

        while(queue.size > 0) {
            var currentList : MutableList<Int> = mutableListOf()
            val levelSize = queue.size
            
            for (i in 1..levelSize) {
                val front = queue.first()
                queue.removeFirst()

                if(front.left != null) {
                    queue.addLast(front.left)
                }

                if(front.right != null) {
                    queue.addLast(front.right)
                }

                currentList.add(front.`val`)
            }
            
            res.add(currentList.toList())
        }

        return res
    }   
}

