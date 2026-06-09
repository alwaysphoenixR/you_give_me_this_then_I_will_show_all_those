class Solution {
public:
void f1(int i,vector<vector<int>>&ans,vector<int>&temp,int k,int n){
    if(i>n){
        if(temp.size()==k)
        ans.push_back(temp);
        return ;
    }
    //exclude 
    f1(i+1,ans,temp,k,n);
    //include 
    if(temp.size()<=k){
        temp.push_back(i);
        f1(i+1,ans,temp,k,n);
        temp.pop_back();
    }
}
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        int i=1;
        f1(i,ans,temp,k,n);
        return ans;
        
    }
};