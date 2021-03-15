class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int length = (num1.size() > num2.size()) ? num2.size() : num1.size();
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int remaind = 0;
        string result="";
        for(int idx=0;idx<length;idx++) {
            int c = (num1[idx] - '0') + (num2[idx] - '0') + remaind;
            remaind  = c/10;
            c = c%10;
            
            result.push_back(c+'0');
        }
        
        int idx=length;
        while(idx < num1.size()) {
            int c = (num1[idx]-'0')+remaind;
            remaind = c/10;
            c=c%10;
            result.push_back(c+'0');
            idx++;
        }
        
        while(idx < num2.size()) {
            int c = (num2[idx]-'0')+remaind;
            remaind = c/10;
            c=c%10;
            result.push_back(c+'0');
            idx++;
        }
        
        if(remaind!=0)
            result.push_back(remaind+'0');
        
        reverse(result.begin(), result.end());
            
        return result;
    }
};