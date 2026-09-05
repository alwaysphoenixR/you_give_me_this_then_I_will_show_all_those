class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = speed.size();
        
        vector<pair<int, int>> nums;
        
        for (int i = 0; i < n; i++) {
            auto p = make_pair(position[i], speed[i]);
            nums.push_back(p);
        }

        sort(nums.begin(), nums.end());

        // Use double because arrival times should not be rounded
        vector<double> f_array(n);

        for (int i = 0; i < n; i++) {
            int dist = nums[i].first;
            int carSpeed = nums[i].second;

            f_array[i] = (double)(target - dist) / carSpeed;
        }
        for(auto i:f_array){
            cout<<i<<" ";
        }
        cout<<endl;

        stack<double> st;
        vector<int> fans(n);

        int ans = 0;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && st.top() < f_array[i]) {
                st.pop();
            }

            // If stack is empty, this car creates a new fleet
            if (st.empty()) {
                fans[i] = -1;
            } else {
                fans[i] = 1;
            }

            st.push(f_array[i]);
        }

        for (int i = 0; i < fans.size(); i++) {
            if (fans[i] == -1) {
                ans++;
            }
        }

        return ans;
    }
};