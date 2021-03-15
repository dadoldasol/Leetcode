class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max=0;
        
        vector<vector<int>> direction {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == 1) {
                    int cur_size = 0;
                    queue<pair<int, int>> q;
                    
                    q.push({i, j});
                    grid[i][j] = 0;
                    
                    while(!q.empty()) {
                        int cur_i = q.front().first;
                        int cur_j = q.front().second;
                        
                        q.pop();
                        
                        cur_size++;
                        
                        for(int d=0;d<4;d++) {
                            int moved_i = cur_i+direction[d][0];
                            int moved_j = cur_j+direction[d][1];
                            
                            if(moved_i < 0 || moved_j < 0 
                               || moved_i >= grid.size() || moved_j >= grid[0].size()
                               || grid[moved_i][moved_j] == 0) 
                                continue;
                            
                            q.push({moved_i, moved_j});
                            grid[moved_i][moved_j] = 0;
                        }
                    }
                    
                    max = (max < cur_size) ? cur_size : max;
                }
            }
        }
        
        return max;
    }
};