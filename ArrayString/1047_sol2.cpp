class Solution {
public:
    string removeDuplicates(string S) {
        string result = "";
        
        for(int idx=0;idx<S.size();idx++) {
            if(result.length() == 0) {
                result += S[idx];
                continue;
            }
            
            char cur = result[result.length()-1];
            
            if(cur == S[idx]) {
                result.erase(result.length()-1, 1);
            } else {
                result += S[idx];
            }
        }
        
        return result;
    }
};