class Solution {
public:
    int power(int base, int e, int mod) {
        long long res = 1;
        long long b = base;
        while(e > 0) {
            if(e%2 == 1) {
                res = (res * b) % mod;
            }
            b = (b*b)%mod;
            e /=2;
        } 
        return res;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        int ans = 0;
        int mod = 1e9 + 7;
        while(i <= j) {
            if(nums[i] + nums[j] > target) {
                j--;
            }else {
                ans = (ans + power(2, j-i, mod)) % mod;
                i++;
            }
        }
        return ans;

    }
};