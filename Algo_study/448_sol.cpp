class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int v_size = nums.size();
        
        vector<int> check(v_size);
        int disap = 0;
        
        for(int idx=0;idx<v_size;idx++) {
            int val = nums[idx];
            
            if(check[val-1] == 1) {
                disap++;
            }
            else {
                check[val-1] = 1;
            }
        }
        
        nums.clear();
        
        for(int idx=0;idx<v_size;idx++) {
            if(check[idx]==0) {
                nums.push_back(idx+1);
            }
        }
        
        return nums;
    }
};