class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        
        sort(intervals.begin(), intervals.end(), 
             [](const vector<int> &a, const vector<int> &b) {return a[0] < b[0];});
        
        result.push_back(intervals[0]);
        
        for(int idx=1;idx<intervals.size();idx++) {
            auto& res_e = result.back();
            if(intervals[idx][0] <= res_e[1]) {
                res_e[1] = (res_e[1] <= intervals[idx][1]) ? intervals[idx][1] : res_e[1];
            }
            else {
                result.push_back(intervals[idx]);
            }
        }
        
        return result;
    }
};