# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if (head == None or head.next == None):
            return head 
        first = head 
        second = head.next
        prev = None 

        while (first != None and second != None):
            third = second.next 

            second.next = first 
            first.next = third 

            if prev != None :
                prev.next = second
            else :
                head = second 
                       
            prev = first 
            first = third 
            
            if (third!=None):
                second= third.next
            else :
                second = None

        return head 

