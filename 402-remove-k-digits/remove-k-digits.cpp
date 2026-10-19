class Solution {
public:
void clean(string &ans){
    string fans;
    int n=ans.size();
    // cout<<n<<endl;
    int i=0;
    while(i<n && ans[i]=='0'){
        i++;
    }
    for(int j=i;j<n;j++){
        fans+=ans[j];
    }
    ans=fans;
}
    string removeKdigits(string num, int k) {
        // I have to handle this starting with zero case 
        int n=num.size();
        cout<<n<<endl;
        if(k>=n)return "0";
        stack<char>st;
        for(int i=0;i<num.size();i++){
            if(st.empty()){
                st.push(num[i]);
            }else{
                while(!st.empty() && st.top()>num[i] && k){
                    st.pop();
                    k--;
                }
                st.push(num[i]);
            }
        }
        while(k){
            st.pop();
            k--;
        }
        string ans;
        if(st.empty())return "0";
        while(!st.empty()){
            auto tp=st.top();
            st.pop();
            ans+=tp;
        }
        reverse(ans.begin(),ans.end());
        clean(ans);
        if(ans=="")return "0";
        return ans;
    }
};