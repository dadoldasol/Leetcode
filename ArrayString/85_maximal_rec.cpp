class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if(matrix.size() == 0)
            return 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> left(m), height(m);
        vector<int> right(m, m);
        
        int result=0;
        for(int i=0;i<n;i++) {
            int cur_left=0, cur_right=m;
            for(int j=0;j<m;j++) {
                if(matrix[i][j] == '1') height[j]++;
                else height[j]=0;
            }
            
            for(int j=0;j<m;j++) {
                if(matrix[i][j] == '1') {
                    left[j] = max(cur_left,left[j]);
                }
                else {
                    left[j] = 0;
                    cur_left = j+1;
                }
            }
            
            for(int j=m-1;j>=0;j--) {
                if(matrix[i][j] == '1') {
                    right[j] = min(cur_right,right[j]);
                }
                else {
                    cur_right = j;
                    right[j] = m;
                }
            }
            
            for(int j=0;j<m;j++) {
                result = max(result, (right[j]-left[j])*height[j]);
            }
        }
        
        return result;
    }
};