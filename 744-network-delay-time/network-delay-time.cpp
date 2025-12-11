class Solution {
public:
    #define pii pair<int,int>
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : times) {
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, k});
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;

        while(!pq.empty()) {
            auto [w, ele] = pq.top(); pq.pop();
            for(auto [nei, wt] : adj[ele]) {
                if(dist[nei] > dist[ele] + wt) {
                    dist[nei] = dist[ele] + wt;
                    pq.push({dist[nei], nei});
                }
            }
        }
        int maxi = -1;
        for(int i = 1; i <= n; i++) {
            maxi = max(maxi, dist[i]);
        }
        return (maxi == 1e9 ? -1 : maxi);
    }
};