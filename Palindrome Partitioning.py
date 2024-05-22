class Solution:
    def partition(self, s: str) -> List[List[str]]:
        result = []
        self._backtrack(s, 0, [], result)
        return result

    def _backtrack(self, s: str, start: int, path: List[str], result: List[List[str]]):
        if start == len(s):
            result.append(path[:])
            return
        
        for end in range(start, len(s)):
            if self._is_palindrome(s, start, end):
                path.append(s[start:end+1])
                self._backtrack(s, end+1, path, result)
                path.pop()

    def _is_palindrome(self, s: str, left: int, right: int) -> bool:
        while left < right:
            if s[left] != s[right]:
                return False
            left += 1
            right -= 1
        return True
