class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int length = (num1.size() > num2.size()) ? num1.size() : num2.size();
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int remaind = 0, idx1=0, idx2=0;
        string result="";
        while(idx1<num1.size() || idx2<num2.size() || remaind) {
            int left = (idx1<num1.size()) ? num1[idx1++]-'0' : 0;
            int right = (idx2<num2.size()) ? num2[idx2++]-'0' : 0;
            
            left = left+right+remaind;
            remaind = left/10;
            result.push_back(left%10+'0');
        }
        
        reverse(result.begin(), result.end());
            
        return result;
    }
};