class Solution {
public:
    pair<int, int> fours[4] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    
    void DFS(vector<vector<char>>& grid, int i, int j) {
        
        grid[i][j] = '0';
        
        for(int k=0;k<4;k++) {
            int new_i = i+fours[k].first;
            int new_j = j+fours[k].second;
            
            if(new_i < 0 || new_j < 0 || new_i >= grid.size() || new_j >= grid[0].size())
                continue;
            
            if(grid[new_i][new_j] == '1')
                DFS(grid, new_i, new_j);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int numIsland=0;
        
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == '1') {
                    numIsland++;
                    DFS(grid, i, j);
                }
            }
        }
        
        return numIsland;
    }
};