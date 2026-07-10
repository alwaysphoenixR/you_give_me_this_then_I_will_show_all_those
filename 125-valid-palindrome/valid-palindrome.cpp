class Solution {
public:
string clean(string &s){
    string temp;
    for(int i=0;i<s.size();i++){
        if(isalnum(s[i])){
            temp+=tolower(s[i]);
        }
    }
    return temp;
}
    bool isPalindrome(string s) {
        if(s== " ")return true;
       string ns=clean(s);
       if(ns==" ")return true;
       int i=0;
       int j=ns.size()-1;
       cout<<ns<<endl;
       while(i<=j ){
        if(ns[i]==ns[j]){
            i++;
            j--;
        }else{
            return false;
        }
       }
       return true;
        
    }
};