# 接雨水

#### *Trapping Rain Water*

给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

![示意图](https://github.com/SherlockUnknowEn/leetcode/blob/master/40-49/40.%20Trapping%20Rain%20Water(Hard)/rainwatertrap.png)

上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。


英文题目:

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


**example 1**

```
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
```


---

### 思路

1. 思路一：初始时海平面为0，从数组左右分别找到第一个比海平面高的柱子，则新的海平面高度可为两个柱子中较小值，计算两个柱子间接入多少水。
2. 如`nums = [0, 2, 5, 0, 3]`,可接入水的计算方式为：

```
初始海平面高0，则左右分别第一个比海平面高的柱子为2和3，下标为left = 1, right = 4

level = min(nums[left], nums[right]) 为新海平面高度

从left下标遍历到right，将低于level的位置注水到level高度，并计数，此时nums = [0, 2, 5, 2, 3]，water = 2

重复此过程，最后返回water
```

3. 思路二：遍历nums，找到最高的两根柱子left，right，在两根柱子中注水，然后在nums[:left+1] 和 nums[right:]未注水的两段递归此过程


### 代码
```
class Solution:


    def trap(self, height):
        '''
        思路一
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
        思路二
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



    # 一层一层计数，若max(nums)很大则时间复杂度太高
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
```
本题以及其它leetcode题目代码github地址: [github地址](https://github.com/SherlockUnknowEn/leetcode)