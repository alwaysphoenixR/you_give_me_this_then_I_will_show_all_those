class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        for(int i=0;i<k;i++){
            int num=arr[i];
            int diff=abs(arr[i]-x);
            pq.push({diff,num});
        }
         
        for(int i=k;i<arr.size();i++){
            int diff=abs(arr[i]-x);
            auto [curr,node]=pq.top();
            if(diff>curr)continue;
           else{
            if(diff==curr){
                if(node<arr[i]){cout<<node<<" "<<arr[i];continue;}
                else{
                     pq.pop();
                pq.push({diff,arr[i]});
                }
            }else{
                 pq.pop();
                pq.push({diff,arr[i]});
            }
           }
        }
        while(!pq.empty()){
            auto [curr,node]=pq.top();
            pq.pop();
        
            ans.push_back(node);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};