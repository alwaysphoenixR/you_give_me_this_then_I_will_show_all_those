class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                if(!st.empty()){
                    st.pop();
                }
            }else{
                st.push(s[i]);
            }
        }
        stack<char>st2;
        for(int i=0;i<t.size();i++){
             if(t[i]=='#'){
                if(!st2.empty()){
                    st2.pop();
                }
            }else{
                st2.push(t[i]);
            }
        }
        string x;
        string y;
        while(!st.empty()){
            x+=st.top();
            st.pop();
        }
        while(!st2.empty()){
            y+=st2.top();
            st2.pop();
        }
        if(x==y)return true;
        return false;
    }
};