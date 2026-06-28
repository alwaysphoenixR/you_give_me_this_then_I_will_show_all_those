class Solution {
public:
void dfs(int &n,int &k,string &temp,string &ans,int &cnt){
    if(temp.size()==n){
        cnt++;
        if(cnt==k){
            ans=temp;
        }
        return ;
    }
    if((temp.empty() || temp.back()!='a') && temp.size()+1<=n){
        temp+='a';
        // cnt++;
        dfs(n,k,temp,ans,cnt);
        temp.pop_back();
    }
    if((temp.empty() || temp.back()!='b') && temp.size()+1<=n){
         temp+='b';
        //  cnt++;
        dfs(n,k,temp,ans,cnt);
        temp.pop_back();
    }
    if((temp.empty() || temp.back()!='c') && temp.size()+1<=n){
         temp+='c';
        //  cnt++;
        dfs(n,k,temp,ans,cnt);
        temp.pop_back();
    }
}
    string getHappyString(int n, int k) {
        string temp="";
        string ans="";
        int cnt=0;
        dfs(n,k,temp,ans,cnt);
        return ans;

        
    }
};