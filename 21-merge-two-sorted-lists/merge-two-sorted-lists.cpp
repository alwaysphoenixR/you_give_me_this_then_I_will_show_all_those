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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* ans_head=NULL;
        ListNode* temp=NULL;
        // cout<<ans_head<<endl;
        while(temp1!=NULL && temp2!=NULL){
            int val1=temp1->val;
            int val2=temp2->val;
            if(val1<val2){
                ListNode* curr_node=new ListNode(val1);
                 if(ans_head==NULL){
            ans_head=curr_node;
            temp=ans_head;
                    cout<<ans_head<<endl;
                    temp1=temp1->next;

        }else{
                temp->next=curr_node;
                temp=curr_node;
                temp1=temp1->next;
        }
            }else{
                ListNode* curr_node=new ListNode(val2);
                 if(ans_head==NULL){
            ans_head=curr_node;
                        temp=ans_head;

                    cout<<ans_head<<endl;
                                        temp2=temp2->next;


        }else{
                temp->next=curr_node;
                temp=curr_node;
                temp2=temp2->next;
        }
            }
            }
            while(temp1!=NULL){
                  ListNode* curr_node=new ListNode(temp1->val);
                   if(ans_head==NULL){
            ans_head=curr_node;
                        temp=ans_head;

                    cout<<ans_head<<endl;
                                        temp1=temp1->next;


        }else{
                temp->next=curr_node;
                temp=curr_node;
                temp1=temp1->next;
        }
            }
            while(temp2!=NULL){
                ListNode* curr_node=new ListNode(temp2->val);
                 if(ans_head==NULL){
                  ans_head=curr_node;
                              temp=ans_head;

                          cout<<ans_head<<endl;
                                              temp2=temp2->next;


        }else{
                temp->next=curr_node;
                temp=curr_node;
                temp2=temp2->next;
        }
            }
            return ans_head;
            
        }
};