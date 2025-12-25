struct logic {
    bool operator()(pair<int,string>& a, pair<int,string>& b) {
        if(a.first == b.first) {
            return a.second < b.second;
        }return a.first > b.first;
    }
};
class Solution {
public:
    #define pp pair<int,string>
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pp, vector<pp>, logic> pq;
        unordered_map<string, int> mp;
        for(string s : words) mp[s]++;
        for(auto it : mp) {
            
            pq.push({it.second, it.first});
            if (pq.size() > k) pq.pop();

        }
        vector<string> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};