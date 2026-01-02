/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int cnt = 0;
        int flag = 1;
        while(head) {
            if(st.find(head->val) != st.end()) {
                if(flag) cnt++;
                flag = 0;
            }else {
                flag = 1;
            }
            head = head->next;
        }
        return cnt;
    }
};