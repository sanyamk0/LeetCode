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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        vector<int> odd, even;
        ListNode* curr = head;
        while (curr && curr->next) {
            odd.push_back(curr->val);
            curr = curr->next->next;
        }
        if (curr)
            odd.push_back(curr->val);
        curr = head->next;
        while (curr && curr->next) {
            even.push_back(curr->val);
            curr = curr->next->next;
        }
        if (curr)
            even.push_back(curr->val);
        curr = head;
        for (int val : odd) {
            curr->val = val;
            curr = curr->next;
        }
        for (int val : even) {
            curr->val = val;
            curr = curr->next;
        }
        return head;
    }
};