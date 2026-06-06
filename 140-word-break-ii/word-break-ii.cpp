class Solution {
public:
void  f1(string &s,set<string>&s1,int start,vector<string>&fans,string &temp){
    if(start>=s.size()){
        temp.pop_back();
        fans.push_back(temp);
        return ;
    }
    for(int i=start;i<s.size();i++){
        string curr = s.substr(start, i - start + 1);
        if(!s1.count(curr))continue;
        int len = temp.size();
    
     temp += curr;
     temp+=" ";
    f1(s, s1, i+1,fans,temp);
      temp.resize(len);
    }
}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        string temp="";
        set<string>s1(wordDict.begin(),wordDict.end());
       f1(s,s1,0,ans,temp);
        return ans;
    }
};