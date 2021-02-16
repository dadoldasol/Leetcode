class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size();i++) {
            int start = i+1;
            int end = nums.size()-1;
            
            int target = -nums[i];
            
            while(start < end) {
                int sum = nums[start] + nums[end];
                
                if(target==sum){
                    result.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--;

                    while(start<end && nums[start] == nums[start-1]) start++;
                    while(start<end && nums[end] == nums[end+1]) end--;
                }
                else if (sum < target){
                    start++;
                }
                else {
                    end--;
                }
            }
            
            while(i + 1 < nums.size() && nums[i] == nums[i+1])
                i++;
        }
        
        return result;
    }
};