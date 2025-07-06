from typing import List

# Solution 1

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:

        sorted_array=sorted(nums1+nums2)
        length =len(sorted_array)
        if(length % 2 == 0):
            middle_right_index=length//2
            middle_left_index=middle_right_index - 1
            median = (sorted_array[middle_left_index]+sorted_array[middle_right_index]) / 2
        else:
            middle_index=length//2
            median = sorted_array[middle_index]

        return median


# Example usage for local testing:
if __name__ == "__main__":
    solution = Solution()
    
    nums1 = [1, 2]
    nums2 = [3, 4]
    
    result = solution.findMedianSortedArrays(nums1, nums2)
    print("Median:", result)
