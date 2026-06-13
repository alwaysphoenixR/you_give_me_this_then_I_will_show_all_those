class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for
        (int i=0;i<words.size();i++){
            int sum=0;
            for(int j=0;j<words[i].size();j++){
                sum+=weights[words[i][j]-'a'];
            }
            sum=sum%26;
            // cout<<sum<<endl;
            int x=(25-sum);
            char y=x+'a';
            cout<<x<<" "<<x+'a'<<endl;
            ans+=y;
        }
        return ans;
    }
};