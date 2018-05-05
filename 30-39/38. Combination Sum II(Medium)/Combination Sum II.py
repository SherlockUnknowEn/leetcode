'''
/*
 * @Author: Fengjie 
 * @Date: 2018-05-03 17:08:09 
 * @Last Modified by: Fengjie
 * @Last Modified time: 2018-05-04 09:45:05
 */
'''

class Solution:
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        result = []
        candidates = sorted(candidates)
        def combin(candidates, target, i, curr):
            if target == 0:
                result.append(list(curr))
                return
            if i >= len(candidates):
                return
            if target < 0:
                return
            if candidates[i] <= target:
                curr.append(candidates[i])
                combin(candidates, target - candidates[i], i+1, curr)
                curr.pop()
                combin(candidates, target, i+1, curr)
            else:
                combin(candidates, target, i+1, curr)
        combin(candidates, target, 0, [])
        result = self.removeSame(result)
        return result

    def removeSame(self, result):
        arr = []
        for x in result:
            d = {}
            for num in x:
                d[num] = (d[num] + 1 if num in d else 1)
            if d not in arr:
                arr.append(d)
        uni_result = []
        for d in arr:
            tmp = []
            for num, count in d.items():
                tmp.extend([num] * count)
            uni_result.append(tmp)
        return uni_result


a = Solution().combinationSum2([10,1,2,7,6,1,5], 8)
print(a)