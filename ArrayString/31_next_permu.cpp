class Solution {
public:
    
    void nextPermutation(vector<int>& nums) {
        int first_d = nums.size()-2;
        while(first_d >= 0 && nums[first_d] >= nums[first_d+1]) first_d--;
        
        if(first_d < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int swap_d = nums.size()-1;
        while(nums[swap_d] <= nums[first_d]) swap_d--;
        
        swap(nums[swap_d], nums[first_d]);
        reverse(nums.begin() + first_d + 1, nums.end());
    }
};