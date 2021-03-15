class Solution {
public:
    // 북, 서, 남, 동
    int direction[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    
    bool isRobotBounded(string instructions) {
        int x=0,y=0, x_dir, y_dir;
        int cur_direction = 0;
        
        for(int idx=0;idx<4;idx++) {
            for(auto i : instructions) {
                x_dir = direction[cur_direction][0];
                y_dir = direction[cur_direction][1];
                
                if(i =='G') {
                    x += x_dir;
                    y += y_dir;
                    
                   // cout << x << " " << y << endl;
                }
                else if(i=='L') {
                    if(cur_direction==3)
                        cur_direction=0;
                    else
                        cur_direction++;
                    
                }
                else if(i=='R') {
                    if(cur_direction==0)
                        cur_direction=3;
                    else
                        cur_direction--;
                }
            }
            
            if(x==0 && y==0)
                return true;
        }
        
        return false;
    }
};