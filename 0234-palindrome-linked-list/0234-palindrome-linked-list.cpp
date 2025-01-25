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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* curr = head;
        while (curr) {
            st.push(curr->val);
            curr = curr->next;
        }
        ListNode* head2 = new ListNode(st.top());
        st.pop();
        ListNode* curr2 = head2;
        while (!st.empty()) {
            ListNode* temp = new ListNode(st.top());
            st.pop();
            curr2->next = temp;
            curr2 = temp;
        }
        curr = head, curr2 = head2;
        while (curr && curr2) {
            if (curr->val != curr2->val)
                return false;
            curr = curr->next;
            curr2 = curr2->next;
        }
        return true;
    }
};