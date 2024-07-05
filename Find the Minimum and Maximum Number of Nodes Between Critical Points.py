class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        # Initialize pointers for traversing the list
        left = head
        mid = head.next

        # Check if the list has at least three nodes
        if not mid.next:
            return [-1, -1]

        right = mid.next

        idx = 2  # Index of the current middle node
        idxs = []  # List to store indices of critical points

        # Traverse the list
        while right:
            # Check for local maxima or minima
            if (mid.val > left.val and mid.val > right.val) or (mid.val < left.val and mid.val < right.val):
                idxs.append(idx)

            # Move to the next set of nodes
            left = mid
            mid = right
            right = right.next
            idx += 1

        # If there are fewer than two critical points, return [-1, -1]
        if len(idxs) < 2:
            return [-1, -1]

        # Find the minimum and maximum distances between critical points
        min_distance = float('inf')
        max_distance = idxs[-1] - idxs[0]

        for i in range(1, len(idxs)):
            min_distance = min(min_distance, idxs[i] - idxs[i - 1])

        return [min_distance, max_distance]
