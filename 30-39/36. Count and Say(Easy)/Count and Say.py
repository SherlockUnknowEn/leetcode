'''
/*
 * @Author: Fengjie 
 * @Date: 2018-05-02 20:31:50 
 * @Last Modified by: Fengjie
 * @Last Modified time: 2018-05-03 09:43:51
 */
'''

# The count-and-say sequence is the sequence of integers with the first five terms as following:

# 1.     1
# 2.     11
# 3.     21
# 4.     1211
# 5.     111221

# 1 is read off as "one 1" or 11.
# 11 is read off as "two 1s" or 21.
# 21 is read off as "one 2, then one 1" or 1211.
# Given an integer n, generate the nth term of the count-and-say sequence.

# Note: Each term of the sequence of integers will be represented as a string.

# Example 1:

# Input: 6
# Output: "312211"

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


a = Solution().countAndSay(6)
print(a)