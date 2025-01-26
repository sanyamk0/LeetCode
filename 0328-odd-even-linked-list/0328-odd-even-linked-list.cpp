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
        vector<int> odd, even;
        ListNode* curr = head;
        int index = 1;
        while (curr) {
            if (index & 1) {
                odd.push_back(curr->val);
            } else {
                even.push_back(curr->val);
            }
            curr = curr->next;
            index++;
        }
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