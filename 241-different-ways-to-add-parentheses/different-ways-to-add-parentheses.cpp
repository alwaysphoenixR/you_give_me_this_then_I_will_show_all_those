class Solution {
public:
bool is_opr(char c){
    return c=='+' || c=='-' || c=='*';
}
vector<int> f1(string s,int start,int end){
    if(end-start+1<=2){
        vector<int>temp;
        temp.push_back(stoi(s.substr(start,end-start+1)));
        return temp;
    }
    vector<int>temp;
    for(int i=start;i<=end;i++){
        if(is_opr(s[i])){
            if(s[i]=='+'){
                int new_e=i-1;
                int new_s=i+1;
                vector<int>l=f1(s,start,new_e);
                vector<int>r=f1(s,new_s,end);
                for(int k=0;k<l.size();k++){
                    for(int p=0;p<r.size();p++){
                        int num=l[k]+r[p];
                        temp.push_back(num);
                    }
                }
            }else if(s[i]=='-'){
                int new_e=i-1;
                int new_s=i+1;
                vector<int>l=f1(s,start,new_e);
                vector<int>r=f1(s,new_s,end);
                for(int k=0;k<l.size();k++){
                    for(int p=0;p<r.size();p++){
                        int num=l[k]-r[p];
                        temp.push_back(num);
                    }
                }
            }else{
                int new_e=i-1;
                int new_s=i+1;
                vector<int>l=f1(s,start,new_e);
                vector<int>r=f1(s,new_s,end);
                for(int k=0;k<l.size();k++){
                    for(int p=0;p<r.size();p++){
                        int num=l[k]*r[p];
                        temp.push_back(num);
                    }
                }
            }
        }
    }
    return temp;
}
    vector<int> diffWaysToCompute(string s) {
        int start=0;
        int end=s.size()-1;
        vector<int>ans=f1(s,start,end);
        return ans;
    }
};