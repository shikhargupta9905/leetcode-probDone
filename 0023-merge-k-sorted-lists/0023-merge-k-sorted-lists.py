# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import heapq
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[Optional[ListNode]]
        :rtype: Optional[ListNode]
        """
        heap =[]

        for head in lists:
            while head:
                heapq.heappush(heap,head.val)
                head= head.next 
        
        if not heap :
            return None
               
        head = ListNode(heapq.heappop(heap))
        curr = head 
        while heap :
            curr.next = ListNode(heapq.heappop(heap))
            curr = curr.next 
        return head 