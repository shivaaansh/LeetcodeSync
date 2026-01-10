class Solution {
public:
    int f(int house, vector<int> &h) {
        int s = 0, e = h.size()-1;
        while(s <= e) {
            int m = (s + e) / 2;
            if(house == h[m]) return 0;
            else if(house > h[m]) {
                s = m+1;
            }else {
                e = m-1;
            }
        }
        int distR = (s < h.size() ? abs(h[s] - house) : INT_MAX);
        int distL = (e >= 0 ? abs(h[e] - house) : INT_MAX);
        return min(distR, distL);
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int minRadius = 0;
        for(int house : houses) {
            int dist = f(house, heaters);
            minRadius = max(minRadius, dist);
        }
        return minRadius;
    }
};