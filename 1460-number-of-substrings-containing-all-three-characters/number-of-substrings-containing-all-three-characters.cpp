class Solution {
public:
    long long int numberOfSubstrings(string s) {
        long long int i = 0, j = 0;
        long long int cnt = 0;
        long long int dc = 0; // distinct character count
        vector<long long int> c(26, 0);
        
        while (j < s.size()) {
            if (c[s[j] - 'a'] == 0) dc++;
            c[s[j] - 'a']++;
            
            while (dc > 2) {
                c[s[i] - 'a']--;
                if (c[s[i] - 'a'] == 0) dc--;
                i++;
            }

            cnt += j - i + 1; // substrings with <= 2 distinct characters
            j++;
        }

        long long int n = s.size();
        long long int total = n * (n + 1) / 2;
        return total - cnt; // substrings with all 3 characters
    }
};
