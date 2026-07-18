class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxii=*max_element(nums.begin(),nums.end());
        int minii=*min_element(nums.begin(),nums.end());
        return __gcd(maxii,minii);
    }
};