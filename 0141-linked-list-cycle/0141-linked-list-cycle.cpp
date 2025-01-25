/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*, int> mp;
        ListNode* curr = head;
        while (curr) {
            if (mp.find(curr) != mp.end())
                return true;
            mp[curr] = 1;
            curr = curr->next;
        }
        return false;
    }
};