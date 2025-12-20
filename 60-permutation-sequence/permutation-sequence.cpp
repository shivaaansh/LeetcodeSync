class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(10, 1);
        for(int i = 1; i <= 9; i++) {
            fact[i] = i * fact[i-1];
        }
        string s;
        k--;
        for(int i = 1; i <= n; i++) {
            s += i + '0';
        }
        for(int i = 1; i <= n; i++) {
            if(k >= fact[n-i]) {
                int j = k / fact[n-i];
                swap(s[i-1], s[i+j-1]);
                sort(s.begin() + i, s.end());
                k = k % fact[n-i];
            }
        }
        return s;
    }
};