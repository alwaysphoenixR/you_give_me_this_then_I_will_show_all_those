class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
         vector<int>ans=arr;
        sort(arr.begin(),arr.end());
        int cnt=1;
        unordered_map<int,int>m1;
        for(int i=0;i<arr.size();i
        ++){
            if(m1.find(arr[i])==m1.end()){
                m1[arr[i]]=cnt++;
            }
        }
       
        for(int i=0;
        i<ans.size();i++){
            ans[i]=m1[ans[i]];
        }
        return ans;
        
    }
};