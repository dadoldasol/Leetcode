class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int start=0, end=0, min_num = nums.size()+1;
        int sum = nums[end];
        
        while(start<=end && end < nums.size()) {
            
            if(sum >= target) {
               // cout << start << " " << end << endl;
                int numofsum = (end - start) + 1;
                min_num = (min_num > numofsum) ? numofsum : min_num;
                
                sum -= nums[start++];
            }
            else {
                if(end != nums.size()-1)
                    sum += nums[++end];
                else
                    end++;
            }
        }
        
        if(min_num == (nums.size()+1))
            return 0;
        else
            return min_num;
    }
};