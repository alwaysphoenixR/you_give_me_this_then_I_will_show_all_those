class Solution {
public:
    int minimumPushes(string word) {
        int cost=0;
        int i=0;
        int wt=1;
        while(i<word.size()){
            if(i%8==0 && i!=0){
                wt++;
            }
            cost+=wt;
            i++;
        }
        return cost;
    }
};