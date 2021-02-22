class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        
        int prev_val = 0;
        bool first = true;
        
        while(!s.empty() || root){
            while(root) {
                s.push(root);
                root = root->left;
            }
            
            root = s.top();
            s.pop();
            
            if(first) {
                first = false;
            }
            else if(prev_val >= root->val)
                return false;
            
            prev_val = root->val;
            root = root->right;
        }
        
        return true;
    }
};