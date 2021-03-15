class Solution {
public:
    int minDepth(TreeNode* root) {
        int min_depth = INT_MAX;
        
        if(!root)
            return 0;
        
        queue<pair<TreeNode*, int>> q;
        
        q.push(make_pair(root, 1));
        
        while(!q.empty()) {
            TreeNode* cur = q.front().first;
            int cur_depth = q.front().second;
            q.pop();
            
            if(cur->left)
                q.push(make_pair(cur->left, cur_depth+1));
            
            if(cur->right)
                q.push(make_pair(cur->right, cur_depth+1));
            
            if(!cur->right && !cur->left)
                min_depth = (min_depth>cur_depth) ? cur_depth:min_depth;
        }
        
        return min_depth;
    }
};