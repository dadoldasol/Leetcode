class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        
        for(int idx=2;idx<size; idx++) {
            cost[idx] = cost[idx] + min(cost[idx-1], cost[idx-2]);
        }
    
        return min(cost[size-1], cost[size-2]);
    }
};