class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        
        vector<int> s,e;
        
        for(auto interv : intervals) {
            s.push_back(interv[0]);
            e.push_back(interv[1]);
        }
        
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());
        
        int res_s=s[0], res_e=e[0];
        for(int idx=1;idx<s.size();idx++) {
            if(s[idx] <= res_e) {
                res_e = e[idx];
            }
            else {
                result.push_back({res_s, res_e});
                
                res_s = s[idx];
                res_e = e[idx];
            }
        }
        
        result.push_back({res_s, res_e});
        
        return result;
    }
};