class Solution {
public:
void f1(vector<string>&ans,int i,string s,int n){
    if(i==n){
        ans.push_back(s);
        return ;
    }
    string temp=s;
    temp+='1';
    f1(ans,i+1,temp,n);
    temp.pop_back();
    if(s.empty() || temp[i-1]=='1'){
        temp+='0';
        f1(ans,i+1,temp,n);
    }
}
    vector<string> validStrings(int n) {
        vector<string>ans;
        int i=0;
        f1(ans,i,"",n);
        return ans;
    }
};