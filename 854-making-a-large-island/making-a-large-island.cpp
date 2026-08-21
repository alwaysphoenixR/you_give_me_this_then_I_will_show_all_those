class Solution {
public:

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    // Check whether (i, j) is inside the grid
    bool check(int i, int j, int N) {
        return (i >= 0 && i < N && j >= 0 && j < N);
    }

    // Check whether we can visit this cell during DFS
    bool is_valid(int i, int j,
                  vector<vector<int>>& vis,
                  vector<vector<int>>& grid) {

        int n = grid.size();

        return (i >= 0 && i < n &&
                j >= 0 && j < n &&
                !vis[i][j] &&
                grid[i][j] == 1);
    }

    // DFS to mark one complete component
    void dfs(int x, int y, int cnt,
             vector<vector<int>>& vis,
             vector<vector<int>>& grid,
             int& sz) {

        vis[x][y] = cnt;
        sz++;

        for (int i = 0; i < 4; i++) {

            int nx = x + dx[i];
            int ny = y + dy[i];

            if (is_valid(nx, ny, vis, grid)) {
                dfs(nx, ny, cnt, vis, grid, sz);
            }
        }
    }

    /*
        We are currently at a cell belonging to component cmp1.

        We try:

            component 1
                 |
                 v
                 0
                 |
                 v
            component 2

        If we find another component through a 0,
        we can change that 0 to 1 and merge both components.

        Answer = size(component1)
               + size(component2)
               + 1
    */
    void merge(int x, int y, int cmp1, int N,
               int& ans,
               unordered_map<int, int>& m1,
               vector<vector<int>>& vis,
               vector<vector<int>>& grid) {

        // First move: find a neighbouring 0
        for (int i = 0; i < 4; i++) {

            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!check(nx, ny, N))
                continue;

            // We need the intermediate cell to be 0
            if (grid[nx][ny] != 0)
                continue;

            // --- YOUR NEW LOGIC STARTS HERE ---
            
            // We are standing on the '0' at (nx, ny).
            // Let's collect all UNIQUE components around this '0'.
            unordered_set<int> unique_cmps;

            // Second move: check all 4 sides of this 0
            for (int j = 0; j < 4; j++) {
                int nxx = nx + dx[j];
                int nyy = ny + dy[j];

                // If valid and it's a part of a component (vis > 0)
                if (check(nxx, nyy, N) && vis[nxx][nyy] != 0) {
                    unique_cmps.insert(vis[nxx][nyy]); 
                }
            }

            // Now, sum up the sizes of these unique components
            int possible_size = 1; // +1 for the '0' we are converting
            for (int id : unique_cmps) {
                possible_size += m1[id];
            }

            // Update the global maximum answer
            ans = max(ans, possible_size);
            
            // --- YOUR NEW LOGIC ENDS HERE ---
        }
    }

    int largestIsland(vector<vector<int>>& grid) {

        int N = grid.size();
        int zerocnt=0;
        // Component ID for every cell
        vector<vector<int>> vis(N, vector<int>(N, 0));

        int cnt = 0;

        /*
            Step 1:
            Find all connected components.

            Example:

            1 1 0
            1 0 1
            0 1 1

            Components get IDs like:

            1 1 0
            1 0 2
            0 2 2
        */
        for (int i = 0; i < N; i++) {

            for (int j = 0; j < N; j++) {
                if(!grid[i][j])zerocnt++;

                if (grid[i][j] == 1 && !vis[i][j]) {

                    cnt++;

                    int sz = 0;

                    dfs(i, j, cnt, vis, grid, sz);
                }
            }
        }

        /*
            Step 2:
            Store size of every component.

            m1[component_id] = component_size
        */
        unordered_map<int, int> m1;

        for (int i = 0; i < N; i++) {

            for (int j = 0; j < N; j++) {

                if (vis[i][j] != 0) {
                    m1[vis[i][j]]++;
                }
            }
        }

        int ans = 0;

        /*
            Step 3:
            For every 1-cell, try to find:

                component1 -> 0 -> component2

            Then merge their sizes.
        */
        for (int i = 0; i < N; i++) {

            for (int j = 0; j < N; j++) {

                if (grid[i][j] == 1) {

                    int cmp1 = vis[i][j];

                    merge(i, j, cmp1, N,
                          ans, m1, vis, grid);
                }
            }
        }

        /*
            Step 4:
            If there was no pair of components to merge,
            we may still be able to make an island by
            converting one 0 next to a component.

            Example:

            1 1
            1 0

            Answer = 4
        */
        for (int i = 0; i < N; i++) {

            for (int j = 0; j < N; j++) {

                if (grid[i][j] == 0) {

                    for (int k = 0; k < 4; k++) {

                        int ni = i + dx[k];
                        int nj = j + dy[k];

                        if (check(ni, nj, N) &&
                            vis[ni][nj] != 0) {

                            ans = max(ans,
                                      m1[vis[ni][nj]] + 1);
                        }
                    }
                }
            }
        }

        /*
            If the whole grid is already 1,
            there is no 0 to change.
        */
        if(zerocnt==N*N)return 1;
        if (ans == 0)
            ans = N * N;

        return ans;
    }
};