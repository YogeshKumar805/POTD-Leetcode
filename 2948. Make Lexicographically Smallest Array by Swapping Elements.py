class Solution:
    def lexicographicallySmallestArray(self, A: List[int], limit: int) -> List[int]:
        arr = sorted((v, i) for i, v in enumerate(A))
        i = 0

        while i < len(A):
            j = i + 1            
            while j < len(A) and arr[j][0] - arr[j - 1][0] <= limit:
                j += 1
            
            idx = sorted(x[1] for x in arr[i:j])
            
            for k in range(len(idx)):
                A[idx[k]] = arr[i + k][0]
            
            i = j

        return A
