class Solution {
public:
bool cc(string &s,int i,int j){
    while(i<=j){
        if(s[i]==s[j]){
            i++;
            j--;
        }
        else{
            return false;
        }

    }
    return true;
}
    bool validPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        if(s==rev)return true;
        int i=0;
        int j=s.size()-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                if((i+1<s.size() && s[i+1]!=s[j]) && (j-1>=0 && s[i]!=s[j-1])){
                    return false;
                }
                return (cc(s,i+1,j) || cc(s,i,j-1));
            }
        }
        return false;
    }
};