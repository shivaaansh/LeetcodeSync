class Solution {
public:
    int dp[201][201];

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for(int i = 0; i + 3 < n; i++) {
            
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j = i + 1; j + 2 < n; j++) {

                if(j > i + 1 && nums[j] == nums[j-1]) continue;

                memset(dp, -1, sizeof(dp)); 

                long long tar = (long long)target - nums[i] - nums[j];
                int k = j + 1, m = n - 1;

                while(k < m) {

                    if(dp[k][m] != -1) {
                        if(nums[k] + nums[m] < tar) k++;
                        else m--;
                        continue;
                    }

                    dp[k][m] = 1;

                    long long sum = nums[k] + nums[m];

                    if(sum == tar) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[m]});

                        k++; m--;
                        while(k < m && nums[k] == nums[k-1]) k++;
                        while(k < m && nums[m] == nums[m+1]) m--;

                    } else if(sum < tar) {
                        k++;

                    } else {
                        m--;
                    }
                }
            }
        }

        return ans;
    }
};
