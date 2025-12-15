class Solution {
public:
    int n, m;
    int MOD = 1e9 + 7;

    vector<vector<long long>> dpMax, dpMin;
    vector<vector<bool>> vis;

    pair<long long, long long> dfs(int i, int j, vector<vector<int>>& grid) {
        // Base case
        if (i == 0 && j == 0)
            return {grid[0][0], grid[0][0]};

        // If already computed
        if (vis[i][j])
            return {dpMax[i][j], dpMin[i][j]};

        long long mx = LLONG_MIN, mn = LLONG_MAX;

        // From top
        if (i > 0) {
            auto [pmx, pmn] = dfs(i - 1, j, grid);
            mx = max(mx, max(pmx * grid[i][j], pmn * grid[i][j]));
            mn = min(mn, min(pmx * grid[i][j], pmn * grid[i][j]));
        }

        // From left
        if (j > 0) {
            auto [pmx, pmn] = dfs(i, j - 1, grid);
            mx = max(mx, max(pmx * grid[i][j], pmn * grid[i][j]));
            mn = min(mn, min(pmx * grid[i][j], pmn * grid[i][j]));
        }

        vis[i][j] = true;
        dpMax[i][j] = mx;
        dpMin[i][j] = mn;

        return {mx, mn};
    }

        int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), MOD = 1e9+7;
        // we use long long to avoid overflow
        vector<vector<long long>>mx(m,vector<long long>(n)), mn(m,vector<long long>(n));
        mx[0][0]=mn[0][0]=grid[0][0];
        
        // initialize the top and left sides
        for(int i=1; i<m; i++){
            mn[i][0] = mx[i][0] = mx[i-1][0] * grid[i][0];
        }
        for(int j=1; j<n; j++){
            mn[0][j] = mx[0][j] = mx[0][j-1] * grid[0][j];
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(grid[i][j] < 0) { // minimum product * negative number = new maximum product
                    mx[i][j] = min(mn[i-1][j], mn[i][j-1]) * grid[i][j];
                    mn[i][j] = max(mx[i-1][j], mx[i][j-1]) * grid[i][j];
                }
                else { // maximum product * positive number = new maximum product
                    mx[i][j] = max(mx[i-1][j], mx[i][j-1]) * grid[i][j];
                    mn[i][j] = min(mn[i-1][j], mn[i][j-1]) * grid[i][j];
                }
            }
        }

        int ans = mx[m-1][n-1] % MOD;
        return ans < 0 ? -1 : ans;
    }
};
