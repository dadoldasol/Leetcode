class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_max = nums[0];
        int pre_max = nums[0];
        
        for(int num = 1; num < nums.size(); num++) {
            pre_max = max(pre_max+nums[num], nums[num]);
            cur_max = max(pre_max, cur_max);
        }
        
        return cur_max;
    }
};