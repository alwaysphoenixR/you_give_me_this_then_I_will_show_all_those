class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        string ans;
        int i=0;
        int n=s.size();
        while(i<n){
            // cout<<s[i]<<endl;
            // starting braces push everything into stack
            if(s[i]=='['){
                st.push("[");
                i++;
            }// you got the ending braces pop everything out and decode with things with the number
            else if(s[i]==']'){
                string temp;
                string num;
                while(!st.empty() && st.top()!="["){
                    auto tp=st.top();
                    // cout<<tp<<endl;
                   temp = tp + temp;
                    st.pop();
                }
                // cout<<temp<<endl;
                // now either stack is empty -->but test cases are generated such that this wont happen
                auto tp=st.top();
                st.pop();
                // reverse(temp.begin(),temp.end());
                num=st.top();
                string x;
                st.pop();
                for(int i=0;i<stoi(num);i++){
                    // cout<<num<<" "<<temp<<endl;
                    x+=temp;
                }
                st.push(x);
                i++;
            }// you got a number 
            else if(!isalpha(s[i])){
                string num_part;
                while(i<n && !isalpha(s[i]) && s[i]!='['){
                    num_part+=s[i];
                    i++;
                }
                st.push(num_part);
            }// all chars 
            else{
                 string x;
                while(i<n && isalpha(s[i])){
                    x+=s[i];
                    i++;
                }
                st.push(x);
                // st.push(s[i]);
                // i++;
            }
        }
        string fans;
        stack<string>st2;
        while(!st.empty()){
            auto tp=st.top();
            cout<<tp<<' ';
            st2.push(tp);
            st.pop();
        }
        cout<<endl;
        // cout<<fans<<endl;
        while(!st2.empty()){
            auto tp=st2.top();
            fans+=tp;
            st2.pop();
        }
        return fans;
    }
};