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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head;
        int sum=0;
        ListNode* ans_head=NULL;
        ListNode* temp_ans=NULL;
        while(temp->next!=NULL){
            temp=temp->next;
            sum+=temp->val;
            if(temp->val==0){
                ListNode* nn=new ListNode(sum);
                if(ans_head==NULL){
                    ans_head=nn;
                    temp_ans=ans_head;
                }else{
                    temp_ans->next=nn;
                    temp_ans=nn;
                }
                sum=0;
            }
        }
        return ans_head;
    }
};