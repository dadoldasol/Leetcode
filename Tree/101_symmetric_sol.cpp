class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        stack<TreeNode*> s;
        
        if(!root)
            return true;
        
        if(!root->left && !root->right)
            return true;
        else if(!root->left || !root->right)
            return false;
        
        s.push(root->left);
        s.push(root->right);
        
        while(!s.empty()) {
            TreeNode* val_r = s.top();
            s.pop();
            TreeNode* val_l = s.top();
            s.pop();
            
            if (val_l->val != val_r->val)
                return false;
            
            if(val_r->right && val_l->left) {
                s.push(val_r->right);
                s.push(val_l->left);
            }
            else if(val_r->right || val_l->left) {
                return false;
            }
            
            if(val_r->left && val_l->right) {
                s.push(val_r->left);
                s.push(val_l->right);
            }
            else if(val_r->left || val_l->right) {
                return false;
            }
        }
        
        return true;
    }
};