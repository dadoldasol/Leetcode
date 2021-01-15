class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        ListNode* odd_cur = head;
        
        if(!head || !head->next)
            return head;
        
        ListNode* even_head = head->next;
        ListNode* even_cur = even_head;
        
        while(even_cur->next)
        {
            odd_cur->next = even_cur->next;
            odd_cur = odd_cur->next;
            
            even_cur->next = odd_cur->next;
            
            if (!odd_cur->next)
                break;
            
            even_cur = odd_cur->next;
        }
        
        odd_cur->next = even_head;
        
        return head;
    }
};