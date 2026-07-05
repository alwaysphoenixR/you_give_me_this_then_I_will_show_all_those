class Solution {
public:
    int dx[3] = {0, -1, -1};
    int dy[3] = {-1, 0, -1};
    const int MOD = 1000000007;

    int dfs(int i, int j, const vector<string>& board,
            vector<vector<int>>& dp) {

        if (i == 0 && j == 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int n = board.size();
        int m = board[0].size();
        int ans = INT_MIN;

        for (int k = 0; k < 3; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                board[nx][ny] != 'X') {
                ans = max(ans, dfs(nx, ny, board, dp));
            }
        }

        if (ans == INT_MIN)
            return dp[i][j] = INT_MIN;

        if (board[i][j] == 'S' || board[i][j] == 'E')
            return dp[i][j] = ans;

        return dp[i][j] = ans + (board[i][j] - '0');
    }

    int dfs2(int i, int j, int target, vector<string>& board,
             vector<vector<vector<int>>>& memo) {

        if (target < 0)
            return 0;

        if (i == 0 && j == 0)
            return target == 0;

        if (memo[i][j][target] != -1)
            return memo[i][j][target];

        int n = board.size();
        int m = board[0].size();

        long long ans = 0;

        for (int k = 0; k < 3; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                board[nx][ny] != 'X') {

                int val = 0;
                if (board[nx][ny] != 'S' && board[nx][ny] != 'E')
                    val = board[nx][ny] - '0';

                ans = (ans + dfs2(nx, ny, target - val, board, memo)) % MOD;
            }
        }

        return memo[i][j][target] = ans;
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = dfs(n - 1, m - 1, board, dp);

        if (ans == INT_MIN)
            return {0, 0};

        // Maximum possible score <= 9 * (2*n - 2)
        int MAX_SCORE = 9 * (2 * n - 2) + 5;

        vector<vector<vector<int>>> memo(
            n, vector<vector<int>>(m, vector<int>(MAX_SCORE, -1)));

        int cnt = dfs2(n - 1, m - 1, ans, board, memo);

        return {ans, cnt};
    }
};