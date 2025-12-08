# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head is None:
            return None
        
        queue = []
        counter = k

        curr = head
        while curr is not None:
            if counter > 1:
                queue.append(curr)
                counter -= 1
            else:
                true_next = curr.next
                q_len = len(queue)
                for i in range(q_len - 1, -1, -1):
                    queue[i].next = (queue[i - 1] if i > 0 else true_next)
            
            curr = curr.next
    
        return head
