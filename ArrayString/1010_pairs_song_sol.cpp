class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int result=0;
        vector<int> c(60);
        
        for(auto t : time) {
            result += c[(60-(t%60))%60];
            c[t%60]++;
        }
        
        return result;
    }
};