class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* c_head = nullptr, * c_cur_n = nullptr;
        unordered_map<Node*, Node*> n_m;
        
        if(!head)
            return c_head;
        
        c_head = new Node(head->val);
        c_cur_n = c_head;
        
        n_m[head] = c_cur_n;
        Node* cur_h = head->next;
        
        while(cur_h) {
            Node* cur_node = new Node(cur_h->val);
            
            c_cur_n->next = cur_node;
            c_cur_n = c_cur_n->next;
            
            n_m[cur_h] = cur_node;
            
            cur_h=cur_h->next;
        }
        
        c_cur_n = c_head;
        cur_h = head;
        
        while(cur_h) {
            
            if(cur_h->random == nullptr){
                c_cur_n->random = nullptr;
                c_cur_n=c_cur_n->next;
                cur_h=cur_h->next;
                continue;
            }
            
            c_cur_n->random = n_m[cur_h->random]; 
            
            c_cur_n = c_cur_n->next;
            cur_h = cur_h->next;
        }
        
        return c_head;
    }
};