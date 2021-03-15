class Solution {
public:
    
    int lenLongestFibSubseq(vector<int>& arr) {
        
        unordered_set<int> s(arr.begin(), arr.end());
        int result=0;
        
        for(int i=0;i<arr.size()-1;i++) {
            for(int j=i+1;j<arr.size();j++) {
                int a=arr[i], b=arr[j], l=2;
                
                while(s.count(a+b)) {
                    b=a+b; a=b-a; l++;
                }
                
                result = max(result, l);
            }
        }
        
        return (result>2)?result:0;
    }
};