class Solution {
public:
    vector<string> in;
    vector<string> result;
    
    void dfs(string digits, string cur_result, int idx) {
        if(idx == digits.size()) {
            result.push_back(cur_result);
            cur_result.clear();
            return;
        }
        
        int cur_idx = digits[idx] - 48;
        for(char& s : in[cur_idx-2]) {
            dfs(digits, cur_result+s, idx+1);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        in.push_back("abc");
        in.push_back("def");
        in.push_back("ghi");
        in.push_back("jkl");
        in.push_back("mno");
        in.push_back("pqrs");
        in.push_back("tuv");
        in.push_back("wxyz");
        
        if(digits.size() == 0)
            return result;
        
        string cur_result="";
        dfs(digits, cur_result, 0);
        
        for(char& s : digits){
            cout << s << endl;
        }
        
        return result;
    }
};