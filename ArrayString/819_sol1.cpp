class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> result;
        vector<string> split_s;
        
        string tmp_s;
        for (int idx=0;idx<paragraph.size();idx++) {
            char cur = paragraph[idx];
            if (cur=='!' || cur=='?' || cur == '\'' || cur ==',' || cur == 59 || cur == '.' || cur == ' ') {
                if (tmp_s.size() != 0) {
                    split_s.push_back(tmp_s);
                    tmp_s.clear();
                }
                
                continue;
            }
            else if (cur >= 65 || cur <= 90) {
                cur = tolower(cur);
            }

            tmp_s += cur;
        }
        
        if (tmp_s.size() != 0) {
            split_s.push_back(tmp_s);
        }
        
        for (auto word : split_s) {
            if (result.count(word) == 0) {
                result[word] = 1;
            }
            else {
                result[word] += 1;
            }
        }
        
        for (auto b_word : banned) {
            if(result.count(b_word)) {
                result[b_word] = -1;
            }
        }
        
        int max=0;
        string res;
        for (auto word : split_s) {
            if(result[word] >= max) {
                max = result[word];
                res = word;
            }
        }
        
        return res;
    }
};