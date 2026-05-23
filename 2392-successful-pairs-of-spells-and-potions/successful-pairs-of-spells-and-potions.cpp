class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        // int n=spells.size();
        int N=potions.size();
        vector<int>fans(n);
        vector<pair<int,int>>nn(n);
        for(int i=0;i<n;i++){
            nn[i].first=spells[i];
            nn[i].second=i;
        }
        int prev_e=potions.size()-1;
        sort(nn.begin(),nn.end());
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            int num=nn[i].first;
            int index=nn[i].second;
            int s=0;
            int e=prev_e;
            int ans=0;
            while(s<=e){
                int mid=(e-s)/2+s;
                if(1ll*num*potions[mid]>=success){
                    ans=N-mid;
                    prev_e=mid;
                    e=mid-1;
                }else{
                    s=mid+1;
                }
            }
            fans[index]=ans;
        }
        return fans;
    }
};