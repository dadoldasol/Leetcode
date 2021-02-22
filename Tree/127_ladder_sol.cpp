class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        queue<string> q;
        q.push(beginWord);
        
        int result=1;
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int q_size=0;q_size<size;q_size++) {
                string cur = q.front();
                q.pop();
                
                dict.erase(cur);
            
                if(cur.compare(endWord) == 0)
                    return result;

                for(int idx=0;idx<cur.size();idx++) {
                    char c = cur[idx];

                    for(int s=0;s<26;s++) {
                        cur[idx] = 'a'+s;

                        if(dict.find(cur) != dict.end()) {
                            q.push(cur);
                            dict.erase(cur);
                        }
                    }
                    cur[idx] = c;
                }
            }
            result++;
        }
        
        return 0;
    }
};