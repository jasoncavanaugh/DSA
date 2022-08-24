from typing import *
def binary_search(nums: List[List[int]], target: int):
    low, high = 0, len(nums)
    while low <= high:
        mid = (low + high)//2
        if nums[mid] < target:
            low = mid + 1
        elif nums[mid] > target:
            high = mid - 1
        else:
            return mid

    return -1
