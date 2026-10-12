# Last updated: 10/12/2026, 9:53:14 PM
class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        return (level := list(accumulate((ch == "(" or -1 for ch in s), initial=0)))[-1] - 2 * min(level)