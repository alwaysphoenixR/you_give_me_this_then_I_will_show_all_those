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
int get_len(ListNode* head){
    int cnt=0;
    ListNode* temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=get_len(headA);
        int len2=get_len(headB);
        int diff=abs(len1-len2);
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        ListNode* y=NULL;
        if(len1>len2){
            // temp1=headA;
            while(diff && temp1!=NULL){
                diff--;
                temp1=temp1->next;
            }
        }else{
            // temp2=headB;
            while(diff && temp2!=NULL){
                diff--;
                temp2=temp2->next;
            }
        }
        while(temp1!=NULL && temp2!=NULL){
            if(temp1==temp2){
                y=temp1;
                break;
            }else{
                temp1=temp1->next;
                temp2=temp2->next;

            }
        }
        return y;
    }
};