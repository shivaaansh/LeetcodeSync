class Solution {
public:
    int totalSteps(vector<int>& nums) {

        // Stack stores pairs: (value, steps_to_die)
        stack<pair<int,int>> st;

        int ans = 0;

        // Traverse from left to right
        for(int i = 0; i < nums.size(); i++) {

            int steps = 0;

            // Pop all elements smaller or equal to current
            // because they cannot kill current element
            while(!st.empty() && st.top().first <= nums[i]) {
                steps = max(steps, st.top().second);
                st.pop();
            }

            // If stack is empty, no larger element to the left
            // so current element never gets removed
            if(st.empty()) {
                steps = 0;
            }
            // Otherwise, it will die 1 step after the strongest left element
            else {
                steps = steps + 1;
            }

            // Update answer
            ans = max(ans, steps);

            // Push current element with its death step
            st.push({nums[i], steps});
        }

        return ans;
    }
};
