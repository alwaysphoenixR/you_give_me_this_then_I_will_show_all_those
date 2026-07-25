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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        int max_dist=INT_MIN;
        int min_dist=INT_MAX;
        vector<int>critical_points;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            if(prev && temp->next){
                int curr_val=temp->val;
                int prev_val=prev->val;
                int nn_val=temp->next->val;
                if((curr_val>prev_val && curr_val>nn_val) || (curr_val<prev_val && curr_val<nn_val)){
                    critical_points.push_back(cnt);
                }
               
            }
             prev=temp;
                temp=temp->next;
        }
    
        if(critical_points.size()<2)return {-1,-1};
        max_dist=critical_points.back()-critical_points[0];
        for(int i=1;i<critical_points.size();i++){
            min_dist=min(min_dist,critical_points[i]-critical_points[i-1]);
        }
        return {min_dist,max_dist};
        
    }
};