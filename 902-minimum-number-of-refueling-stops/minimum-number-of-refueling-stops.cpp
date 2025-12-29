class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq; // storing highest refill available from previous visits
        int n = stations.size();
        int maxi = startFuel;
        int i = 0;
        int cnt = 0;
        while(maxi < target) {
            while(i < n && maxi >= stations[i][0]) {
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()) {
                return -1;
            }
            maxi += pq.top();
            cnt++;
            pq.pop();
        }
        return cnt;
    }
};