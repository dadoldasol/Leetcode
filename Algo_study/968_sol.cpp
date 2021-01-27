class Solution {
public:
    int sum=0;
    int dfs(TreeNode* root) {
        
        if(!root)
            return 0;   // no need 
        
        int res_l = dfs(root->left);
        int res_r = dfs(root->right);
        
        if (res_l == 1 || res_r == 1){  // no camera
            sum++;
            return 2;
        }
        else if (res_l == 2 || res_r == 2) {    // has camera
            return 0;
        }
        else {
            return 1;   // no need
        }
    }
    
    int minCameraCover(TreeNode* root) {
        if(dfs(root) == 1) sum++;   // no camera
        
        return sum;
    }
};