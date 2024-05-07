# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return
        current = head
        newHead = dummy = ListNode(0)
        number = 0

        while current:
          number = number * 10 + current.val
          current = current.next
        
        number *= 2

        if number == 0:
            return ListNode(0)

        numbers = []
        
        while number > 0:
          digit = number % 10
          number = number // 10
          numbers.append(digit)

        for num in reversed(numbers):
          dummy.next = ListNode(num)
          dummy = dummy.next
        
        return newHead.next
