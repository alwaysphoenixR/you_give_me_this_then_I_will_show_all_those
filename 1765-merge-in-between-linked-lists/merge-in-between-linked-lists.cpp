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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        if(list1==NULL)return list2;
        int cnt=-1;
        ListNode* a_=NULL;
        ListNode* b_=NULL;
        ListNode* b_prev_=NULL;
        ListNode* temp=list1;
        ListNode* prev=temp;
        while(temp!=NULL){
            cnt++;
            if(cnt==a-1){
                a_=temp;
                cout<<a_->val<<endl;
            }
            if(cnt==b+1){
                b_=temp;
                b_prev_=prev;
                                cout<<b_->val<<endl;

                break;
            }
            prev=temp;
            temp=temp->next;
        }
        a_->next=list2;
        ListNode* temp2=list2;
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        temp2->next=b_;
        b_prev_->next=NULL;
        return list1;
        
    }
};