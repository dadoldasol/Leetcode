class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> um;
        
        for(int i=0;i<routes.size();i++) {
            for(int j : routes[i]) {
                um[j].push_back(i);
            }
        }
        
        queue<pair<int, int>> q;
        q.push(make_pair(source, 0));
        
        unordered_set<int> checked;
        checked.insert(source);
        
        while(!q.empty()) {
            int cur_stop = q.front().first;
            int bus_num = q.front().second;
            q.pop();
            
            if(cur_stop == target)
                return bus_num;
            
            for(auto i : um[cur_stop]) {
                for(auto j : routes[i]) {
                    if(!checked.count(j)) {
                        q.push(make_pair(j, bus_num+1));
                        checked.insert(j);
                    }
                }
                routes[i].clear();
            }
        }
        
        return -1;
    }
};