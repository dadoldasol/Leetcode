class Solution {
public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        
        if(!root)
            return result;
        
        stack<TreeNode*> tree_s;
        tree_s.push(root);
        
        TreeNode* cur;
        
        while(!tree_s.empty()) {
            cur = tree_s.top();
            tree_s.pop();
            
            result.push_back(cur->val);
            
            if(cur->right) tree_s.push(cur->right);
            if(cur->left) tree_s.push(cur->left);
        }
        
        return result;
    }
};