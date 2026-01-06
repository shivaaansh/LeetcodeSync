class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        unordered_set<string> st;
        queue<pair<int,int>> q;
        q.push({0, 0});
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                auto [i, j] = q.front(); q.pop();
                ans.push_back(nums[i][j]);
                if(i+1 < nums.size() && j < nums[i+1].size() ) {
                    string s = to_string(i+1) + "*" + to_string(j);
                    if(st.find(s) == st.end()) {
                        q.push({i+1, j}); st.insert(s);}
                }
                if(j+1 < nums[i].size()) {
                    string s = to_string(i) + "*" + to_string(j+1);
                    if(st.find(s) == st.end()) {
                        q.push({i, j+1});
                        st.insert(s);
                    }
                        
                }
            }
        }
        return ans;
    }
};