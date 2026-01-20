class Solution {
public:
    int dp[1001][1001];
    int f(int i, int j, string s1, string s2) {
        if(i < 0 && j < 0) return 0;
        if(i < 0) {
            int sum = 0;
            for(int k = j; k >= 0; k--) {
                sum += s2[k];
            }
            return sum;
        }
        if(j < 0) {
            int sum = 0;
            for(int k = i; k >= 0; k--) {
                sum += s1[k];
            }
            return sum;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int sum = INT_MAX;
        if(s1[i] == s2[j]) {
            sum = min(sum, f(i-1, j-1, s1, s2));
        }
        else {
            sum = min(sum, min(s1[i] + f(i-1, j, s1, s2), s2[j] + f(i, j-1, s1, s2)));
        }
        return dp[i][j] = sum;
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        }
        for (int j = 1; j <= m; j++) {
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(
                        s1[i - 1] + dp[i - 1][j],
                        s2[j - 1] + dp[i][j - 1]
                    );
                }
            }
        }

        return dp[n][m];
    }

};