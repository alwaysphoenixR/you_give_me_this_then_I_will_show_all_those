class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int j=0;
        string ans;
        for(int i=0;i<s.size();i++){
            if(j<spaces.size() && spaces[j]==i){
                ans+=' ';
                j++;
            }
            ans+=s[i];
        }
        return ans;
    }
};