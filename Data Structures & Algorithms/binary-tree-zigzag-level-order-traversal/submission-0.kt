/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */

class Solution {
    fun zigzagLevelOrder(root: TreeNode?): List<List<Int>> {
        if(root == null) {
            return listOf()
        }
        
        val queue = ArrayDeque<TreeNode>()
        queue.add(root)
        
        val res : MutableList<List<Int>> = mutableListOf()
        var depth : Int = 0
        while(queue.size > 0) {
            val currentSize = queue.size
            val currentList = mutableListOf<Int>()
                        
            for(i in 0 until currentSize) {
                val front = queue.first()
                queue.removeFirst()
                
                currentList.add(front.`val`)
                    
                if(front.left != null) 
                    queue.add(front.left)
                
                if(front.right != null) 
                    queue.add(front.right)   
            }
            
            if(depth % 2 == 1) {
                currentList.reverse()
            }

            res.add(currentList)
            ++depth 
        } 
        
        return res
    }
}
