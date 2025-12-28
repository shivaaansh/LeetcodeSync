struct node {
    int data, row, col;
    node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
};
struct cmp {
    bool operator() (node* a, node* b) {
        return a->data > b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX;
        int n = nums.size();
        int maxi = INT_MIN;
        priority_queue<node*, vector<node*>, cmp> pq;
        for(int i = 0; i < n; i++) {
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);
            pq.push(new node(nums[i][0], i, 0));
        }
        int start = mini, end = maxi;
        while(!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            if(cur->col+1 < nums[cur->row].size()) {
                int r = cur->row;
                int c = cur->col + 1;
                pq.push(new node(nums[r][c], r, c));
                mini = pq.top()->data;
                maxi = max(maxi, nums[r][c]);
                if(maxi - mini < end - start) {
                    start = mini;
                    end = maxi;
                }
            }else break;
        }
        return {start, end};
    }
};