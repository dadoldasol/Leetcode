class Solution {
public:
    int minDepth(TreeNode* root) {        
        if(!root)
            return 0;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        int result=0;
        while(!q.empty()) {
            TreeNode* cur = q.front();
            int size = q.size();
            result++;
            
            for(int i=0;i<size;i++) {
                cur = q.front();
                q.pop();
                
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                
                if(!cur->left && !cur->right)
                    return result;
            }
        }
        
        return 0;
    }
};