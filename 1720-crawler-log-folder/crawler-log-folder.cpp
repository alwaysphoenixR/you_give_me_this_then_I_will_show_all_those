class Solution {
public:
void decode(string &s,stack<int>&st){
    if(s=="../"){
        if(!st.empty())
        st.pop();
        return;
    }else if(s=="./"){
        return;
    }else{
        st.push(12);
        return;
    }
}
    int minOperations(vector<string>& logs) {
        stack<int>st;
        for(int i=0;i<logs.size();i++){
            decode(logs[i],st);
        }
        return st.size();
    }
};