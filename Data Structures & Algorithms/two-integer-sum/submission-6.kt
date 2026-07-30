class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        var map : HashMap<Int, Int> = hashMapOf()
        
        for(i in nums.indices) {
            val difference = target - nums[i]

            if(map.containsKey(difference)) {
                return intArrayOf(map[difference]!!, i)
            }
            else {
                map.put(nums[i], i)
            }
        }

        return intArrayOf()
    }
}
