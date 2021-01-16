class Solution {
public:
    ListNode* reculsiveFunc(ListNode* head) {
        if (!head)
            return head;
        
        ListNode* cur=head;
        int sum=0;
        
        while(cur)
        {
            sum += cur->val;
            cur = cur->next;
            
            if(sum == 0)
            {
                return reculsiveFunc(cur);
            }
        }
        head->next = reculsiveFunc(head->next);
        
        return head;
    }
    
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        return reculsiveFunc(head);
    }
};