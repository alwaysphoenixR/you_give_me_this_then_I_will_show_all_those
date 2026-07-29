// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
// void delete_node(ListNode* & temp,ListNode* &prev,ListNode* &head){
//     // head
//     if (prev==NULL){
//         ListNode* nn=temp->next;
//         temp->next=NULL;
//         delete(temp);
//         temp=nn;
//         head=temp;
//         return;
//     }
//     // middle
//     if(prev!=NULL && temp->next!=NULL){
//         ListNode* nn=temp->next;
//         prev->next=nn;
//         temp->next=NULL;
//         delete(temp);
//         temp=nn;
//         return ;
//     }

//     // tail
//     prev->next=NULL;
//     delete(temp);
//     temp=NULL;
//     return ;
// }

//     ListNode* modifiedList(vector<int>& nums, ListNode* head) {
//         vector<int>freq(1e5+1,0);
//         for(int i=0;i<nums.size();i++){
//             freq[nums[i]]++;
//         }
//         ListNode* temp=head;
//         ListNode * prev=NULL;
//         while(temp!=NULL){
//             if(freq[temp->val]){
//                 // freq[temp->val]--;
//                 delete_node(temp,prev,head);
                
//             }else{
//                 prev=temp;
//                 temp=temp->next;
//             }
//         }
//         return head;
//     }
// };

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
    void delete_node(ListNode* &temp, ListNode* &prev, ListNode* &head) {
        // Delete head
        if (prev == NULL) {
            ListNode* nn = temp->next;
            // delete temp;
            temp = nn;
            head = temp;
            return;
        }

        // Delete middle
        if (temp->next != NULL) {
            ListNode* nn = temp->next;
            prev->next = nn;
            // delete temp;
            temp = nn;
            return;
        }

        // Delete tail
        prev->next = NULL;
        // delete temp;
        temp = NULL;
    }
    void print_ll(ListNode* &head){
        ListNode* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<int> freq(100001, 0);

        for (int x : nums)
            freq[x] = 1;          // Presence is enough
        // set<int>s1(nums.begin(),nums.end());

        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {
            // cout<<temp->val<<" "<<endl;
            if (freq[temp->val]) {
                delete_node(temp, prev, head);
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        print_ll(head);
        return head;
    }
};