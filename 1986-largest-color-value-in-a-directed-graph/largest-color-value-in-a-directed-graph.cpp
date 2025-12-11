class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> ind(n, 0);
        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            ind[it[1]]++;
        }

        // dp[i][c] = max count of color 'c' on any path ending at node i
        vector<vector<int>> dp(n, vector<int>(26, 0));

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (ind[i] == 0)
                q.push(i);
        }

        int visited = 0;
        int ans = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited++;
            int colorIndex = colors[node] - 'a';
            dp[node][colorIndex]++;
            ans = max(ans, dp[node][colorIndex]);
            for (int nei : adj[node]) {
                for (int c = 0; c < 26; c++) {
                    dp[nei][c] = max(dp[nei][c], dp[node][c]);
                }
                ind[nei]--;
                if (ind[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        if (visited != n)
            return -1;

        return ans;
    }
};
