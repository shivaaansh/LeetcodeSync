class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int i = 0, j = 0;
        int n = s.size();
        int maxi = 0;
        while(j < n) {
            if(st.find(s[j]) == st.end()) {
                st.insert(s[j]);
                maxi = max(maxi, j - i + 1);
            }else {
                while(i < j && st.find(s[j]) != st.end()) {
                    st.erase(s[i]);
                    i++;
                }st.insert(s[j]);
            }
            j++;
        }
        return maxi;
    }
};