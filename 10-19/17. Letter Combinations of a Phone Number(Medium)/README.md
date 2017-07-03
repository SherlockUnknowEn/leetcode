# 九宫格键盘输入
#### *Letter Combinations of a Phone Number*

* 给定一个数字字符串，返回数字可能代表的所有可能的字母组合。
* 数字到字母的映射（就像九宫格电话按钮一样）如下图。

![九宫格图片](https://github.com/SherlockUnknowEn/leetcode/blob/master/10-19/17.%20Letter%20Combinations%20of%20a%20Phone%20Number(Medium)/img/Telephone.svg.png)

* Given a digit string, return all possible letter combinations that the number could represent.
* A mapping of digit to letters (just like on the telephone buttons) is given below.

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

**example 1**
```
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
```

### 思路
1. 以`23`为例，`2`代表`abc`，只需要将其转换成list`s = [a,b,c]`，然后处理`3`，`3`为`def`，将这三个字符分别加到`s`的每一个元素中，得到`["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]`。重复此过程即可。
2. 上述思路可以用循环完成，同时python提供的reduce函数和生成式特性能够精炼地表述，下面给出两种代码。

### 代码
```
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        from functools import reduce #python3.x
        if not digits:
            return []
        nums = '0 1 abc def ghi jkl mno pqrs tuv wxyz'.split(' ')
        return reduce(lambda last, d: [x + y for x in last for y in nums[int(d)]], digits, [''])  # 第三个参数是initial



    


	#使用循环完成
	def letterCombinations_old(self, digits):
        if not digits:
            return []
        nums = '0 1 abc def ghi jkl mno pqrs tuv wxyz'.split(' ')
        ret = [_ for _ in nums[int(digits[0])]]
        digits = digits[1:]
        while digits:
            ret = [x + y for x in ret for y in nums[int(digits[0])]]
            digits = digits[1:]
        return ret
```