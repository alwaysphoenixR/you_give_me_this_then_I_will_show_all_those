class Solution {
public:
    bool canConstruct(string s, int k) {
            int odd_cnt=0;
            int pair_cnt=0;
            vector<int>nums(26,0);
            for(int i=0;i<s.size();i++){
                nums[s[i]-'a']++;
            }
            for(int i=0;i<nums.size();i++){
                pair_cnt+=nums[i]/2;
                odd_cnt+=nums[i]%2;
            }
            if(s.size()<k)return false;
            if(odd_cnt>k)return false;
            // if(pair_cnt*2>=k)return true;
            // if(odd_cnt+pair_cnt>=k)return true;
            return true;
    }
};