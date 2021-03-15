class Solution {
public:
    vector<vector<int>> direction {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> rot;
        
        int total=0, rot_cnt=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] != 0) total++;
                if(grid[i][j] == 2) rot.push(make_pair(i,j));
            }
        }
        
        int minute = 0;
        while(!rot.empty()) {
            int size = rot.size();
            rot_cnt+=size;
            
            for(int k=0;k<size;k++) {
                int cur_m = rot.front().first;
                int cur_n = rot.front().second;
                rot.pop();
                
                for(int d=0;d<4;d++){
                    int move_m = cur_m + direction[d][0];
                    int move_n = cur_n + direction[d][1];
                    
                    if(move_m < 0 || move_n < 0 || move_m >= m || move_n >= n || (grid[move_m][move_n] != 1)) {
                        continue;
                    }
                    
                    rot.push(make_pair(move_m, move_n));
                    grid[move_m][move_n] = 2;
                }
            }
            
            if(!rot.empty()) minute++;
        }
        
        return (total==rot_cnt) ? minute : -1;
    }
};