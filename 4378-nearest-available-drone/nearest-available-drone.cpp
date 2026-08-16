class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans=-1;
        int val=INT_MAX;
        for(int i=0;i<drones.size();i++){
            int curr=abs(drones[i][0]-target[0])+abs(drones[i][1]-target[1]);
            if(curr<=drones[i][2] && curr<val){
                ans=i;
                val=curr;
            }
        }
        return ans;
    }
};