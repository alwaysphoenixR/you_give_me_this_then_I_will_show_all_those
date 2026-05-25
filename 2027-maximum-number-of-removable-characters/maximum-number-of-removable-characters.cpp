class Solution {
public:
bool can_we(string s,string p,unordered_map<int,int>&m1,int mid){
    int j=0;
    for(int i=0;i<s.size();i++){
        if(m1.find(i)!=m1.end() && m1[i]<mid)continue;
        if (s[i]==p[j]){
            j++;
        }
    }
    if(j>=p.size())return true;
    return false;
}
    int maximumRemovals(string s, string p, vector<int>& removable) {
        unordered_map<int,int>m1;
        for(int i=0;i<removable.size();i++){
            m1[removable[i]]=i;
        }
        int start=0;
        int e=removable.size();
        int ans=0;
        while(start<=e){
            int mid=(e-start)/2+start;
            if(can_we(s,p,m1,mid)){
                ans=mid;
                start=mid+1;
            }else{
                e=mid-1;
            }
        }
        return ans;
        
    }
};