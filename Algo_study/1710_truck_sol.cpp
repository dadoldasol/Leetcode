class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>&a, const vector<int>&b)
             { return a[1] > b[1]; }
             );
        
        int result=0;
        
        for(auto box : boxTypes) {
            int boxnum = box[0];
            int unitnum = box[1];
            
            int boxnumused = (truckSize > boxnum) ? boxnum : truckSize;
            truckSize -= boxnumused;
            
           // cout << boxnumused << " " << truckSize << endl;
            
            result += boxnumused*unitnum;
            
            if(!truckSize)
                break;
        }
        
        return result;
    }
};