class Solution(object):
    def addTwoNumbers(self, l1, l2):
        # Initialize dummy head and current pointer
        dummy = ListNode(0)
        current = dummy
        carry = 0
        
        # Traverse both lists
        while l1 or l2 or carry:
            # Get digit values (0 if list ended)
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            
            # Calculate total
            total = val1 + val2 + carry
            carry = total // 10
            current.next = ListNode(total % 10)
            
            # Move pointers
            current = current.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        
        return dummy.next  # Skip dummy head