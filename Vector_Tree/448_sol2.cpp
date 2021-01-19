class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        
        for(int idx=0;idx<nums.size();idx++) {
            int temp = (nums[idx]>0) ? nums[idx] : -nums[idx];
            temp = temp-1;
            if(nums[temp] > 0) {
                nums[temp] = -nums[temp];
            }
        }
        
        for(int idx=0;idx<nums.size();idx++) {
            if(nums[idx] > 0) {
                result.push_back(idx+1);
            }
        }
        
        return result;
    }
};