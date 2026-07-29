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
int get_len(ListNode* head){
    ListNode* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* n1=NULL;
        ListNode* n2=NULL;
        int n=get_len(head);
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL){
            cnt++;
            if(cnt==k){
                n1=temp;
            }
            if(cnt==(n-k+1)){
                n2=temp;
                // break;
            }
            temp=temp->next;
        }
        int v=n1->val;
        n1->val=n2->val;
        n2->val=v;
        return head;
    }
};