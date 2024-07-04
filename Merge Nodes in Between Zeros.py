# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: ListNode) -> ListNode:
        # Initialize the dummy node for the new linked list.
        dummy = ListNode(0)
        current = dummy
        
        # Skip the initial 0
        head = head.next
        
        # To hold the current sum
        current_sum = 0
        
        while head is not None:
            if head.val == 0:
                # We encountered a zero, finalize the current sum
                if current_sum > 0:
                    current.next = ListNode(current_sum)
                    current = current.next
                # Reset the sum for the next segment
                current_sum = 0
            else:
                # Add value to the current sum
                current_sum += head.val
            
            # Move to the next node
            head = head.next
        
        return dummy.next
 
