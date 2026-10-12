# Last updated: 10/12/2026, 9:55:04 PM
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        s= set()
        for i in nums:
            if i in s:
                return True
            s.add(i)
        return False
        