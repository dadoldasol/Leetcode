class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0, j=0, srem = -1, prem=-1;
        
        while(i < s.size()) {
            if(j < p.size() && ((s[i]==p[j]) || p[j] == '?')) {
                i++; j++;
            }
            else if (j < p.size() && p[j] == '*') {
                prem = j;
                srem = i;
                j++;
            }
            else if (prem != -1) {
                j = prem+1;
                srem++;
                i = srem;
            }
            else
                return false;
        }
        
        while(p[j]=='*' && j<p.size()) j++;
        
        return (j==p.size());
    }
};