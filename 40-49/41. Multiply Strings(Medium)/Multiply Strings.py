'''
/*
 * @Author: Fengjie 
 * @Date: 2018-05-08 16:54:27 
 * @Last Modified by:   Fengjie 
 * @Last Modified time: 2018-05-08 16:54:27 
 */
'''
class Solution:
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        num1_int = 0
        num2_int = 0
        for i in range(len(num1)):
            num1_int += (ord(num1[i]) - 48) * 10**(len(num1) -i -1)
        for i in range(len(num2)):
            num2_int += (ord(num2[i]) - 48) * 10**(len(num2) -i -1)
        result_int = num1_int * num2_int
        result_str = ''
        while result_int > 0:
            ascode = result_int % 10
            result_str = chr(ascode + 48) + result_str
            result_int = result_int // 10
        return result_str if result_str else '0'

a = Solution().multiply('123', '')
print(a)