class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        st.push(asteroids[0]);
        for(int i=1;i<asteroids.size();i++){
            if(st.empty()){st.push(asteroids[i]);continue;}
            auto tp=st.top();
            int nxt=asteroids[i];
            if(tp<0 && nxt<0 || tp>0 && nxt>0  || tp<0 && nxt>0){
                st.push(nxt);
            }
            else if(abs(tp)==abs(nxt)){
                st.pop();
            }else{
                if(abs(tp)>abs(nxt)){
                    continue;
                }else{
                    while(!st.empty() && st.top()>0 && nxt<0 && abs(st.top())<abs(nxt)){
                        cout<<"hi"<<endl;
                         st.pop();
                    }
                    if(!st.empty()){
                        // cout<<"helllo"<<endl;
                        if(st.top()>0 && abs(st.top())==abs(nxt)){
                            // cout<<"bye"<<endl;
                            st.pop();
                            continue;
                        }
                        
                        else if(st.top()<0){st.push(nxt);}
                    }else{
                        st.push(nxt);
                        continue;
                    }
                    
                }
            }
        }
        vector<int>ans;
        while(!st.empty()){
            auto tp=st.top();
            ans.push_back(tp);
            st.pop();
        }
        // ans.push_back(nxt);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};