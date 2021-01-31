class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        
        int h_size = height.size();
        
        if (h_size <= 2)
            return 0;
        
        vector<int> left_s(h_size), right_s(h_size);
        
        int max_h = height[0];
        int max_h_l = height[h_size-1];
        for (int idx=1;idx<h_size;idx++) {
            if (height[idx-1] <= height[idx] && max_h <= height[idx]) {
                left_s[idx] = 0;
            }
            else {
                int cur_w = left_s[idx-1] + (height[idx-1] - height[idx]);
                left_s[idx] = cur_w;
            }
            
            if (height[h_size-(idx+1)] >= height[h_size - idx] && max_h_l <= height[h_size-(idx+1)]) {
                right_s[h_size-(idx+1)] = 0;
            }
            else {
                int cur_w = right_s[h_size-idx] + (height[h_size-idx] - height[h_size-(idx+1)]);
                right_s[h_size-(idx+1)] = cur_w;
            }
            
            max_h = (height[idx] >= max_h) ? height[idx] : max_h;
            max_h_l = (height[h_size-(idx+1)] >= max_h_l) ? height[h_size-(idx+1)] : max_h_l;
        }
        
        for (int idx=0;idx<h_size;idx++) {
            result += right_s[idx] >= left_s[idx] ? left_s[idx] : right_s[idx];
        }
        
        return result;
    }
};