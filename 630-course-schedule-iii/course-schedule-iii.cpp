class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        if(courses.size() == 0) return 0;
        sort(courses.begin(), courses.end(), [&] (auto &a, auto &b) {
            return a[1] < b[1];
        });
        priority_queue<int> pq;
        int maxi = 0, sum = 0;
        for(auto i : courses) {
            sum += i[0];
            pq.push(i[0]);
            if(sum > i[1]) {
                sum -= pq.top();
                pq.pop();
            }
            maxi = max(maxi, (int)pq.size());
        }
        return maxi;
    }
};