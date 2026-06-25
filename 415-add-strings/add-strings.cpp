class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1;
        int j=num2.size()-1;
        int s=0;
        int c=0;
        string ans="";
        while(i>=0 && j>=0){
           int n1=num1[i]-'0';
           int n2=num2[j]-'0';
           s=n1+n2+c;
           ans+=((s%10)+'0');
           c=s/10;
           i--;
           j--;
            }
            while(j>=0){
                //   int n1=num1[i]-'0';
           int n2=num2[j]-'0';
           s=n2+c;
           ans+=((s%10)+'0');
           c=s/10;
           j--;
            }
            while(i>=0){
              int n1=num1[i]-'0';
           s=n1+c;
           ans+=((s%10)+'0');
           c=s/10;
           i--;
            }
            if(c){
             ans+=(c+'0');
            }
            reverse(ans.begin(),ans.end());
            return ans;
    }
};