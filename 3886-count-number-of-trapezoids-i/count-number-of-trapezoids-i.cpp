class Solution {
public:
    const int MOD = 1e9 + 7;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> freq;
        for (auto &p : points)
            freq[p[1]]++;

        long long sum = 0, sumSq = 0;
        for (auto &[y, cnt] : freq) {
            if (cnt >= 2) {
                long long pc = 1LL * cnt * (cnt - 1) / 2;
                sum = (sum + pc) % MOD;
                sumSq = (sumSq + pc * pc % MOD) % MOD;
            }
        }

        long long total = ( (sum * sum % MOD - sumSq + MOD) % MOD ) * ((MOD + 1) / 2) % MOD;
        return (int)total;
    }
};