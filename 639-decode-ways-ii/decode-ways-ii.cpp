class Solution {
public:
    set<string> st = {
        "1",  "2",  "3",  "4",  "5",  "6",  "7",  "8",  "9",
        "10", "11", "12", "13", "14", "15", "16", "17", "18",
        "19", "20", "21", "22", "23", "24", "25", "26"
    };

    int f1(string &s, int i,vector<int>&dp) {
        if (i >= s.size()) {
            return 1;
        }
        if(dp[i]!=-1)return dp[i];
        long long ans = 0;

        for (int j = i; j < s.size() && j < i + 2; j++) {
            string temp = s.substr(i, j - i + 1);

            if (temp.find('*') != string::npos) {

                if (temp.size() == 1) {
                    ans = (ans + 1ll *9 * f1(s, j + 1,dp) % (1000000007))%1000000007;
                } else {

                    if (temp[0] == '*' && temp[1] == '*') {

                        ans = (ans + 1ll *15 * f1(s, j + 1,dp) % (1000000007))%1000000007;

                    } else if (temp[0] == '*' && temp[1] != '*') {

                        if (temp[1] - '0' < 7) {
                            ans = (ans + 1ll *2 * f1(s, j + 1,dp) % (1000000007))%1000000007;
                        } else {
                            ans = (ans + f1(s, j + 1,dp) % (1000000007))%1000000007;
                        }

                    } else {

                        if (temp[0] - '0' < 3) {
                            if(temp[0]-'0'==0)continue;
                            else if (temp[0] - '0' == 1) {
                                ans = (ans + 1ll *9 * f1(s, j + 1,dp) % (1000000007))%1000000007;
                            } else {
                                ans = (ans + 1ll *6 * f1(s, j + 1,dp) % (1000000007))%1000000007;
                            }
                        }
                    }
                }

            } else {

                if (st.count(temp)) {
                    ans = (ans + 1ll *f1(s, j + 1,dp) % (1000000007))%1000000007;
                }
            }
        }

        return dp[i]=ans%1000000007;
    }

    int numDecodings(string s) {
        
        vector<int>dp(s.size(),-1);
        return f1(s, 0,dp);
    }
};