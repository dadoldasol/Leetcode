class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> s;
        heights.push_back(0);
        
        int sizemax=0;
        for(int idx=0;idx<heights.size();idx++) {
            
            while(s.size() && heights[s.top()] >= heights[idx]) {
                int h = heights[s.top()];
                s.pop();
                
                int index = s.size() ? s.top() : -1;
                
                int tmp_size = (idx-index-1)*h;
         //       cout << index << " " << tmp_size << endl;
                sizemax = max(sizemax, tmp_size);
            }
            s.push(idx);
        }
        
        return sizemax;
    }
};