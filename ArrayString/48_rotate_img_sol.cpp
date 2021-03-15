class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        
        int i=0,j=size-1;
        
        while(i<j) {
            for(int idx=0;idx<j-i;idx++) {
                swap(matrix[i][i+idx], matrix[i+idx][j]);
                swap(matrix[i][i+idx], matrix[j][j-idx]);
                swap(matrix[i][i+idx], matrix[j-idx][i]);
            }
            i++;
            j--;
        }
    }
};