class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<int,int>m1;
        set<char>s1(word.begin(),word.end());
        for(auto it:s1){
            auto  x=it;
            char y=tolower(x);
            m1[y-'a']++;
        }
        int ans=0;
        for(auto [key,val]:m1){
            if(val==2)ans++;
        }
        return ans;
    }
};