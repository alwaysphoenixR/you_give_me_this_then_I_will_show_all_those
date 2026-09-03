class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int>ans;
        int j=0;
        for(int i=0;i<pushed.size();i++){
           ans.push_back(pushed[i]);
           while(j<popped.size() && !ans.empty() && popped[j]==ans.back()){
            ans.pop_back();
            j++;
           }
        }
        if(j>=popped.size())return true;
        return false;
        
        
    }
};