class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur_node = head;
        ListNode* next_node = nullptr;
        
        while(cur_node != nullptr && cur_node->next != nullptr)
        {
            next_node = cur_node->next;
            
            if (cur_node->val == next_node->val)
            {
                cur_node->next = next_node->next;
            }
            else
            {
                cur_node = cur_node->next;
            }
        }
        
        return head;
    }
};