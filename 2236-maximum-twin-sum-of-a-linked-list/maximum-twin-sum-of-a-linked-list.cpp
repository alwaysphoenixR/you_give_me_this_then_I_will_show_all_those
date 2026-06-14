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
int getcount(ListNode* head){
    ListNode* temp=head;
    int cnt=0;
    while(temp){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
    int pairSum(ListNode* head) {
        int cnt=0;
        ListNode *temp=head;
        int n=getcount(head);
        unordered_map<int,int>m1;
        while(temp){
            int idx=min(cnt,n-1-cnt);
            m1[idx]+=temp->val;
            cnt++;
            temp=temp->next;
        }
        int ans=0;
        for(auto [key,val]:m1){
            ans=max(ans,val);
        }
        return ans;
    }
};