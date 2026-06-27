class Solution {
public:
void f1(vector<string>&ans,string temp,int st,string &s,int cnt){
    if(st>=s.size() && cnt==4){
        temp.pop_back();
        ans.push_back(temp);
        return;
    }
    for(int i=st;i<s.size();i++){
        string ss=s.substr(st,i-st+1);
        // cout<<ss<<" ";
        if(ss.size()>1 && ss[0]=='0' || i-st+1>3)continue;
        else{
                string x=temp;
            if(stoll(ss)>=0 && stoll(ss)<=255 && cnt<4){
                x+=ss;
                x+='.';
                f1(ans,x,i+1,s,cnt+1);
            }
        }
    }
    // cout<<endl;
}
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        string temp="";
        int st=0;
        f1(ans,temp,st,s,0);
        return ans;        
    }
};