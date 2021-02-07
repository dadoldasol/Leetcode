class Solution {
public:
    void recursive(TreeNode* cur, vector<int>& result) {
        if(!cur) 
            return;
        
        recursive(cur->left, result);
        recursive(cur->right, result);
        
        result.push_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        
        recursive(root, result);
        
        return result;
    }
};