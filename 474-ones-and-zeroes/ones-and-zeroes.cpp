class Solution {
public:
    int dp[601][101][101];
    int f(int i, vector<pair<int,int>> &v, int m, int n) {
        if(i == v.size()) {
            return 0;
        }
        if(dp[i][m][n] != -1) return dp[i][m][n];
        int ntake = f(i+1, v, m, n);
        int take = 0;
        if(m >= v[i].first && n >= v[i].second) {
            take = 1 + f(i+1, v, m - v[i].first, n - v[i].second);
        }
        return dp[i][m][n] = max(take, ntake);

    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> v;
        for(string s : strs) {
            int o = 0, z = 0;
            for(char c : s) {
                if(c == '1') {
                    o++;
                }else z++;
            }
            
            v.push_back({z, o});
        }
        memset(dp, -1, sizeof(dp));
        return f(0, v, m, n);
    }
};