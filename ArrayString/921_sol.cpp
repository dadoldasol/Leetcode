class Solution {
public:
    int minAddToMakeValid(string S) {
        string result = "";
        int r_length = result.size();
        
        for(char& c : S){
            // bool ismatch = (result.back()=='(' && c==')');
            if(result.size() && (result.back()=='(' && c==')')) {
                result.pop_back();
            }
            else {
                result.push_back(c);
            }
        }
        
        return result.size();
    }
};