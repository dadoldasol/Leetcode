class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_s;
        vector<int> result;
        
        for(int idx=0;idx<nums.size();idx++) {
            int find_n = target - nums[idx];
            
            if (num_s.count(find_n) == 1) {
                result.push_back(idx);
                result.push_back(num_s[find_n]);
                
                return result;
            }
            else {
                num_s[nums[idx]] = idx;
            }
        }
        
        return result;
    }
};