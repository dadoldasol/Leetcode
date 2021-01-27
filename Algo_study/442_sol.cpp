class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        
        int num_size = nums.size();
        
        for(int idx=0;idx<num_size;idx++) {
            int temp = (nums[idx]<0) ? (-1 * nums[idx])-1 : nums[idx]-1;
            
            if (nums[temp] > 0) {
                nums[temp] = (-1 * nums[temp]);
            } 
            else {
                result.push_back(temp+1);
            }
        }
        
        return result;
    }
};