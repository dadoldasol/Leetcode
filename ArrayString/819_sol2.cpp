class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> result;
        
        for (int idx=0;idx<paragraph.size();) {
            string tmp_s = "";
            while(idx<paragraph.size() && isalpha(paragraph[idx])) {
                tmp_s.push_back(tolower(paragraph[idx++]));
            }
        
            while(idx<paragraph.size() && !isalpha(paragraph[idx])) {
                idx++;
            }
            
            if(tmp_s.size())
                result[tmp_s]++;
        }
        
        for (auto b : banned) {
            result[b] = 0;
        }
        
        int max_idx=0;
        string res;
        for(auto word : result) {
            if(word.second > max_idx) { 
                max_idx = word.second;
                res = word.first;
            }
        }
        return res;
    }
};