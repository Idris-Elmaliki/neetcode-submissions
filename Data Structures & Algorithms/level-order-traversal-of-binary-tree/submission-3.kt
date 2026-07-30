/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */

class Solution {
    fun levelOrder(root: TreeNode?): List<List<Int>> {
        if(root == null)
            return listOf()

        var list : MutableList<List<Int>> = mutableListOf()

        val queue : ArrayDeque<TreeNode> = ArrayDeque()
        queue.add(root)

        while(queue.size > 0) {
            var currentList = mutableListOf<Int>()

            for(i in queue.indices) {
                val front = queue.first()
                queue.removeFirst()

                currentList.add(front.`val`)

                if(front.left != null) {
                    queue.add(front.left)
                }

                if(front.right != null) {
                    queue.add(front.right)
                }
            }

            list.add(currentList.toList())
        }

        return list 
    }
}
