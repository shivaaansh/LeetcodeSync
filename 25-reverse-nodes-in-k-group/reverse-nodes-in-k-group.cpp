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
    ListNode* fxn(ListNode* globalPrev, ListNode* head, int k) {
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        for(int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } 
        globalPrev->next = prev;
        head->next = curr;
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        int n = 0;
        while (head != nullptr) {
            head = head->next;
            n++;
        }
        head = dummy->next;
        ListNode* prev = dummy;
        int parts = n/k;
        
        for(int i = 0; i < parts; i++) {
            prev = fxn(prev, head, k);
            head = prev->next;
        }
        return dummy->next;
    }
};