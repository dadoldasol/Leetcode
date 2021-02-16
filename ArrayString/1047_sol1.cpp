class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        
        for(int idx=0;idx<S.size();idx++) {
            if(st.empty()) {
                st.push(S[idx]);
                continue;
            }
            
            char cur = st.top();
            
            if(cur == S[idx]) {
                st.pop();
            } else {
                st.push(S[idx]);
            }
        }
        
        S = "";
        
        while(!st.empty()) {
            S += st.top();
            st.pop();
        }
        
        reverse(S.begin(), S.end());
        
        return S;
    }
};