# 报数

#### *Count and Say*

报数序列是指一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：

```	
	1.     1
	2.     11
	3.     21
	4.     1211
	5.     111221
```

`1` 被读作  `"one 1"`  (`"一个一"`) , 即 `11`。

`11` 被读作 `"two 1s"` (`"两个一"`）, 即 `21`。

`21` 被读作 `"one 2"`,  `"one 1"` （`"一个二"` ,  `"一个一"`) , 即 `1211`。

给定一个正整数 n ，输出报数序列的第 n 项。

注意：整数顺序将表示为一个字符串。

英文题目:

* The count-and-say sequence is the sequence of integers with the first five terms as following:
	* `1` is read off as `"one 1"` or `11`.
	* `11` is read off as `"two 1s"` or `21`.
	* `21` is read off as `"one 2, then one 1"` or `1211`.
* Given an integer n, generate the nth term of the count-and-say sequence.
* Note: Each term of the sequence of integers will be represented as a string.


**example**

```
Input: 6

Output: "312211"
```


---

### 思路

1. `say`变量保存第n-1个报数序列
2. 从遍历`say`字符串，`say[0]`保存为`curr_num`，用`count`计数，当遇到不为`curr_num`的元素x时，得到报数序列`str(count) + curr_num`
3. 把`count`置为1，因为遇到不为`curr_num`的元素x时，x已经出现一次，同时`curr_num = x`
4. 从n=2开始循环上述过程到n



### 代码
```
class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        say = '1'
        tmp = ''
        for _ in range(1, n):
            curr_num = say[0]
            count = 0
            for x in say:
                if x == curr_num:
                    count += 1 #count
                else:
                    tmp = tmp + str(count) + curr_num #say
                    curr_num = x
                    count = 1 # x != curr_num时, x已经出现过一次
            tmp = tmp + str(count) + curr_num
            say, tmp = tmp, ''
        return say
```
本题以及其它leetcode题目代码github地址: [github地址](https://github.com/SherlockUnknowEn/leetcode)