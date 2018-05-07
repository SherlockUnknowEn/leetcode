'''
/*
 * @Author: Fengjie 
 * @Date: 2018-05-04 11:14:41 
 * @Last Modified by: Fengjie
 * @Last Modified time: 2018-05-04 11:20:28
 */
'''

import numpy as np
class Solution:


    def trap(self, height):
        '''
        :param height: List[]
        :return: water: int
        '''
        level = 0
        water = 0
        left, right = 0, len(height) - 1
        while left < right:
            while height[left] <= level and left < right:
                left += 1
            while height[right] <= level and left < right:
                right -= 1
            level = min(height[left], height[right])
            for x in range(left, right):
                if height[x] < level:
                    water += level - height[x]
                    height[x] = level
        return water



    def trap2(self, height):
        '''
        :param height: List[]
        :return: water: int
        '''
        water = 0

        def de_trap(start, end):
            nonlocal water
            if (end - start <= 1):
                return
            left, right = self.height_top2(height, start, end)
            water += min(height[left], height[right]) * (right - left - 1)
            water = water - sum(height[left+1:right])
            de_trap(start, left+1)
            de_trap(right, end)

        de_trap(0, len(height))
        return water



    def height_top2(self, height, start, end):
        t1, top2 = (start, start+1) if height[start] > height[start + 1] else (start+1, start)
        top2 = [top2]

        for i in range(start + 2, end):
            if height[i] > height[t1]:
                top2 = [t1]
                t1 = i
            elif height[i] == height[t1]:
                return t1, i
            elif height[i] > height[top2[0]]:
                top2 = [i]
            elif height[i] == height[top2[0]]:
                top2.append(i)
            
        width = 0
        for i in range(len(top2)):
            w = abs(t1 - top2[i])
            if w > width:
                width = w
                t2 = top2[i]
        t1, t2 = min(t1, t2), max(t1, t2)
        return t1, t2



    # 一层一层计数， 时间复杂度太高
    # def trap3(self, height):
    #     """
    #     :type height: List[int]
    #     :rtype: int
    #     """
    #     if not height:
    #         return 0
    #     count = 0
    #     level = 1 #自底向上
    #     top_level = max(height)
    #     while level <= top_level:
    #         left = -1
    #         for i in range(len(height)):
    #             if height[i] >= level:
    #                 left = i
    #                 break
    #
    #         for i in range(left+1, len(height)):
    #             if height[i] >= level:
    #                 count += (i - left - 1)
    #                 left = i
    #         level += 1
    #     return count



a = Solution().trap([0,1,0,2,1,0,1,3,2,1,2,1]) # 6
b = Solution().trap([2,1,0,2]) # 3
c = Solution().trap([3,0,2,0, 1]) #3
d = Solution().trap([0,1,0,2,1,0,1,3,2,1,2,1]) #6
print(a)
print(b)
print(c)
print(d)
