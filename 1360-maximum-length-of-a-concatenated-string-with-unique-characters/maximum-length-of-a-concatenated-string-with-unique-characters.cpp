class Solution {
public:
bool can_we(string &s){
    set<char>s1(s.begin(),s.end());
    if(s.size()==s1.size())return true;
    return false;
}
void f1(vector<string>&arr,string &temp,int &ans,int i){
    if(i>=arr.size()){
        int sz=temp.size();
        ans=max(ans,sz);
        return ;
    }
    // string curr=arr[i];
    int szz=arr[i].size();
    int idx=temp.size();
    temp+=arr[i];
    if(can_we(temp)){
        f1(arr,temp,ans,i+1);
    }
    temp.erase(idx,szz);
    f1(arr,temp,ans,i+1);
}
    int maxLength(vector<string>& arr) {
        int ans=0;
        string temp="";
        f1(arr,temp,ans,0);
        return ans;
    }
};