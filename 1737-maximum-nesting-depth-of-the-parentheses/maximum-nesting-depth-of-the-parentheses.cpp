class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int ans=INT_MIN;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
                ans=max(ans,int(st.size()));
            }else if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                }
            }else{
                continue;
            }
        }
        if(ans==INT_MIN) return 0;
        return ans;
    }
};