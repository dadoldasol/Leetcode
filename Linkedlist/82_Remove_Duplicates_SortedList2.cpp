class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = head;
        bool flag = true;
        
        while (cur && cur->next)
        {
            ListNode* n_node = cur->next;
            if (cur->val == n_node->val)
            {
                cur->next = n_node->next;
                flag = false;
            }
            else
            {
                if (flag)
                {
                    prev = cur;
                    cur = n_node;
                }
                else
                {
                    if(head->val == cur->val)
                    {
                        head = n_node;
                        prev = n_node;
                    }
                    else
                    {
                        prev->next = n_node;
                    }

                    cur = n_node;
                    flag = true;
                }
            }
        }
        
        if(flag == false)
        {
            if(head->val == cur->val)
            {
                head = nullptr;
            }
            prev->next = nullptr;
        }
        
        return head;
    }
};