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
ListNode* findMiddle(ListNode* head,ListNode* &slow0){
    ListNode* fast=head;
    ListNode* slow=head;
    slow0=NULL;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow0=slow;
            slow=slow->next;
        }
    }
    return slow;
}
    ListNode* deleteMiddle(ListNode* head) {
        //single node
        if (head->next==NULL){
            return NULL;
        }
        ListNode* before;
        ListNode* middle=findMiddle(head,before);
        if(middle->next==NULL){
            before->next=NULL;
            return head;
        }
        //normal
        ListNode* after=middle->next;
        before->next=after;
        middle->next=NULL;
        return head;
        
    }
};