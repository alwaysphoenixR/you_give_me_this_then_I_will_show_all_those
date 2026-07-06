class Solution {
public:
    int minimumLength(string s) {
        vector<int>mp(26,0);
        for(int i=0;i<s.size();i++){
            mp[s[i]-'a']++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(mp[i]!=0 && mp[i]%2!=0){
                ans+=1;
            }
           else if(mp[i]!=0 && mp[i]%2==0){
            ans+=2;
           }
        }
        return ans;
        
    }
};