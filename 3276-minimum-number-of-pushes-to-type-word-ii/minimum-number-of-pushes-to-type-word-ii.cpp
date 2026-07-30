class Solution {
public:
bool static cmp(int & a,int & b ){
    return a>b;
}
    int minimumPushes(string word) {
        vector<int>nums;
        vector<int>freq(26,0);
        for(int i=0;i<word.size();i++){
            freq[word[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
              nums.push_back(freq[i]);
            }
        }
        int cost=0;
        int wt=1;
        sort(nums.begin(),nums.end(),cmp);
        for(int i=0;i<nums.size();i++){
            if(i!=0 && i%8==0)wt++;
            cost=cost+(nums[i]*1LL*wt);
        }
        return cost;
    }
};