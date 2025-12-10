class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<vector<int>> adj(rooms.size());
        for(int i = 0; i < rooms.size(); i++) {
            for(int it : rooms[i]) 
                adj[i].push_back(it);
        }
        queue<int> q;
        q.push(0);
        // unordered_set<int> st;
        vector<int> vis(rooms.size(), 0);
        vis[0] = 1;
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            for(auto it : adj[top]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        for(int i = 0; i < rooms.size(); i++) {
            if(vis[i] != 1) return false;
        }
        return true;
    }
};