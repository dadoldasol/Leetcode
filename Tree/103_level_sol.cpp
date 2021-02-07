class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if(!root)
            return result;
        
        queue<TreeNode*> first_q;
        
        first_q.push(root);
        int level=1;
        int next_level=0;
        
        while(!first_q.empty()) {
            vector<int> temp;
            TreeNode* cur;
            
            while(level) {
                cur = first_q.front();
                first_q.pop();
                level--;
                
                temp.push_back(cur->val);
            
                if(level%2 == 0) {
                    if(cur->left) {
                        first_q.push(cur->left);
                        level++;
                    }
                    if(cur->right) {
                        first_q.push(cur->right);
                        level++;
                    }
                }
                else {
                    if(cur->right) {
                        first_q.push(cur->right);
                        level++;
                    }
                    if(cur->left) {
                        first_q.push(cur->left);
                        level++;
                    }
                }
            }
            
            result.push_back(temp);
        }
        
        return result;
    }
};