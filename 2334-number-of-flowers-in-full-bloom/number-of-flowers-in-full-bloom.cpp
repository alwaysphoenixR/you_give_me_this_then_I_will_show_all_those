class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<pair<int,pair<int,int>>>events;
        for(int i=0;i<flowers.size();i++){
            int l=flowers[i][0];
            int r=flowers[i][1];
            events.push_back({l,{1,1}});
            events.push_back({r,{3,-1}});
        }
        for(int i=0;i<people.size();i++){
            int query=people[i];
            events.push_back({query,{2,i}});
        }
        vector<int>ans(people.size());
        int cnt=0;
        sort(events.begin(),events.end());
        for(int i=0;i<events.size();i++){
            int type=events[i].second.first;
            int pos=events[i].first;
            if(type==1){
                int j=i;
                while(j<events.size() && events[j].second.first==type && events[j].first==pos){
                    cnt+=1;
                    j++;
                    i=j-1;
                }
            }else if(type==2){
                int j=i;
                while(j<events.size() && events[j].second.first==type && events[j].first==pos){
                    int idx=events[j].second.second;
                    ans[idx]=cnt;
                    j++;
                    i=j-1;
                }
            }else{
                 int j=i;
                while(j<events.size() && events[j].second.first==type && events[j].first==pos){
                    cnt-=1;
                    j++;
                    i=j-1;
                }
            }
        }
        return ans;
    }
};