# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head):
        if head is None or head.next is None:
            return head
        
        prev = None
        h2 = self.reverseList(head.next)
        head.next.next = head
        head.next = prev
        return h2
