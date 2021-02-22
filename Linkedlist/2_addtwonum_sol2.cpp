class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        
        int saved_val = 0;
        while(l1||l2||saved_val) {
            int val=saved_val;
            if(l1) {
                val += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                val += l2->val;
                l2 = l2->next;
            }
            
            cur->next = new ListNode(val%10);
            saved_val = val/10;
            
            cur=cur->next;
        }
        
        return head->next;
    }
};