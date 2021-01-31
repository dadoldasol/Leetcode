class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        
        for(int x=0;x<nums.size()-1;x++) {
            for(int y=1;y<nums.size();y++) {
                if((x!=y) && nums[x] + nums[y] == target) {
                    result.push_back(x);
                    result.push_back(y);
                    
                    break;
                }
            }
            
            if(result.size() == 2)
                break;
        }
        
        return result;
    }
};