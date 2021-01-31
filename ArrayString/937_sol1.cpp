class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> result_d;
        map<string, set<string>> result_l;
        
        for(auto log : logs) {
            string id = "";
            int idx=0;
            
            while(idx<log.size() && log[idx] != ' ') id.push_back(log[idx++]);
            
            if(isalpha(log[++idx])) {
                result_l[log.substr(idx,log.size())].insert(id);
            }
            else {
                result_d.push_back(log);
            }
        }
        
        vector<string> res;
        
        for(auto letter : result_l) {
            for(auto let : letter.second)
                res.push_back(let + " " + letter.first);
        }
        
        res.insert(res.end(), result_d.begin(), result_d.end());
        
        return res;
    }
};