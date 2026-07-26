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
    void deleteNode(ListNode* node) {
    ListNode* prev = NULL;
    ListNode* curr = node;

    while (curr->next != NULL) {
        curr->val = curr->next->val; // copy next value
        prev = curr;                 // keep second-last
        curr = curr->next;
    }

    // curr is last node
    // prev is second-last node
    prev->next = NULL;
    delete curr;
}
};