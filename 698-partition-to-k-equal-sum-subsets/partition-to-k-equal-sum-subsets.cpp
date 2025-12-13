class Solution {
public:
    int ptsum;
    vector<int> used;
    int f(vector<int> &nums, int i, int k, int sum) {
        if(k == 0) {
            return 1;
        }
        if(sum == ptsum) {
            return f(nums, 0, k-1, 0);
        }
        for(int j = i; j < nums.size(); j++) {
            if(used[j] || sum + nums[j] > ptsum) {
                continue;
            }
            used[j] = 1;
            if(f(nums, j, k, sum + nums[j])) {
                return 1;
            }
            used[j] = 0;
        }
        return 0;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        long long sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        if(sum % k != 0){
            return false;
        }
        ptsum = sum / k;
        if(ptsum < nums[0]){
            return false;
        }
        used.resize(n, 0);
        return f(nums, 0, k, 0);
    }
};