class Solution {
public:
void f1(int &ans,int &sz,unordered_map<char,int>&m1,int cnt){
    if(cnt==sz){
        ans++;
        return;
    }
    for(auto[key,val]:m1){
        if(val!=0){
            m1[key]--;
            f1(ans,sz,m1,cnt+1);
            m1[key]++;
        }
    }
}
    int numTilePossibilities(string tiles) {
        int ans=0;
        unordered_map<char,int>m1;
        for(int i=0;i<tiles.size();i++){
            m1[tiles[i]]++;
        }

        for(int i=1;i<=tiles.size();i++){
            f1(ans,i,m1,0);
        }
        return ans;
    }
};