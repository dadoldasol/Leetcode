class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head, *result;
        
        head = new ListNode(0);
        result = head;
        
        int saved_val = 0;
        while(l1 || l2) {
            int val=0;
            if(l1) {
                val = l1->val;
                l1 = l1->next;
            }
            
            if(l2) {
                val += l2->val;
                l2 = l2->next;
            }
            
            int res = (val+saved_val)%10;
            saved_val = (val+saved_val)/10;
            
            ListNode* newnode = new ListNode(res);
            result->next = newnode;
            result = result->next;
        }
        
        if(saved_val!=0) {
            ListNode* newnode = new ListNode(saved_val);
            result->next = newnode;
        }
        
        return head->next;
    }
};