'''
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
'''

class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        median_idx = int((len(nums1) + len(nums2)) / 2)
        index1, index2 = 0, len(nums1)
        list1 = nums1 + nums2
        list2 = []
        i = 0
        while i <= median_idx:
            if index1 < len(nums1) and index2 - len(nums1) < len(nums2):
                list2.append(min(list1[index1], list1[index2]))
                if list1[index1] < list1[index2]:
                    index1 += 1
                else:
                    index2 += 1
            elif index1 >= len(nums1):
                list2.append(list1[index2])
                index2 += 1
            elif index2 >= len(nums2):
                list2.append(list1[index1])
                index1 += 1
            i += 1
        if (len(nums1) + len(nums2)) % 2 == 0:
            median = float(list2[median_idx] + list2[median_idx - 1]) / 2
        else:
            median = list2[median_idx]

        return median

a = Solution().findMedianSortedArrays([1], [2,3,4])
print(a)