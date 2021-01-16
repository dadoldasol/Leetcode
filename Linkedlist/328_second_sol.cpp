class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if (!head)
            return head;
        
        ListNode* odd_cur = head;
                
        ListNode* even_head = head->next;
        ListNode* even_cur = even_head;
        
        while(even_cur && even_cur->next)
        {
            odd_cur->next = even_cur->next;
            odd_cur = odd_cur->next;
            
            even_cur->next = odd_cur->next;
            even_cur = even_cur->next;
        }
        
        odd_cur->next = even_head;
        
        return head;
    }
};