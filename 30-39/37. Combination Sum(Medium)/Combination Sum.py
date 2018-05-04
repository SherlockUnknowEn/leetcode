'''
/*
 * @Author: Fengjie 
 * @Date: 2018-05-02 21:07:57 
 * @Last Modified by: Fengjie
 * @Last Modified time: 2018-05-04 10:12:06
 */
'''

class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        result = []
        def combin(candidates, target, i, curr):
            if target == 0:
                result.append(list(curr)) #找到解
                return
            if i >= len(candidates):
                return
            if target < 0:
                return
            if candidates[i] <= target:
                curr.append(candidates[i])                          #尝试一个解
                combin(candidates, target - candidates[i], i, curr) #转化为子问题
                curr.pop()                                          #回溯
                combin(candidates, target, i+1, curr)               #尝试另一个解
            else:
                combin(candidates, target, i+1, curr)
        combin(candidates, target, 0, [])
        return result
    

a = Solution().combinationSum([2,3,5], 8)
b = Solution().combinationSum([10,1,2,7,6,5], 8)
print(a)
print(sorted(b))