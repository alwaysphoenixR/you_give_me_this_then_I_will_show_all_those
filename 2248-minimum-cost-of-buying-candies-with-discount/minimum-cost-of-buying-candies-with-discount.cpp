class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        int rem=n%3;
        int q=n/3;
        sort(cost.begin(),cost.end());
        int cnt=0;
        int i=0;
        int ans=0;
        while(cnt<rem){
            ans+=cost[i];
            i++;
            cnt++;
        }
        cout<<i<<" "<<cost.size()-2<<endl;
        
        for(int j=i;j<n-2;j+=3){
            ans+=cost[j+1];
            ans+=cost[j+2];
        }
        return ans;
        
    }
};