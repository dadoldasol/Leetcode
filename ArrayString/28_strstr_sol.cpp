class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(!needle.length()) 
            return 0;
        
        
        for(int idx=0;idx<haystack.length();idx++) {
            
            if(needle[0] == haystack[idx]) {
                int tmp_idx = idx;
                while(++tmp_idx < haystack.length() &&
                     (tmp_idx - idx) < needle.length()) {
                    if(needle[tmp_idx-idx] != haystack[tmp_idx])
                        break;
                }
                if(tmp_idx-idx == needle.length())
                    return idx;
            }
        }
        
        return -1;
    }
};