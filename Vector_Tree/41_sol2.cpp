class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        
        for (int idx=0;idx<size;idx++) {
            if(nums[idx]<=0) {
                nums[idx] = size+1;
            }
        }
        
        for (int idx=0;idx<size;idx++) {
            int tmp = (nums[idx] <= 0) ? nums[idx] * -1 : nums[idx];
            if(tmp <= size && nums[tmp-1] > 0) {
                nums[tmp-1] = nums[tmp-1] * -1;          
            }
        }
        
        for (int idx=0;idx<size;idx++) {
            if(nums[idx] > 0) {
                return idx+1;
            }
        }
        
        return size+1;
    }
};