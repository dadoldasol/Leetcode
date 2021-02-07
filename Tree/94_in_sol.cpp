class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        
        if(!root)
            return result;
        
        stack<TreeNode*> tree_s;
        
        while(!tree_s.empty() || root) {
            while(root) {
                tree_s.push(root);
                
                root = root->left;
            }
            
            root = tree_s.top();
            tree_s.pop();
            
            result.push_back(root->val);
            root = root->right;
        }
        
        
        return result;
    }
};