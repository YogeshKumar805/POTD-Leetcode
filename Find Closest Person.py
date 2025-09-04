class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        return 0 if abs(z-x)==abs(z-y) else (2 if abs(z-x)>abs(z-y) else 1)
