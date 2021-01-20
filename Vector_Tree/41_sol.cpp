class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int size = nums.size();
        
        if(size==0)
            return 1;
        
        vector<int> extra(size);
        
        for(int idx=0;idx<size;idx++) {
            if (nums[idx] > 0 && nums[idx] <= size) {
                extra[nums[idx]-1] = 1;
            }
        }
        
        int small=0;
        
        for(int idx=0;idx<=size;idx++) {
            if(idx==size) {
                small = size+1;
                break;
            }
            
            if(extra[idx] == 0) {
                small = idx+1;
                break;
            }
        }
        
        return small;
    }
};