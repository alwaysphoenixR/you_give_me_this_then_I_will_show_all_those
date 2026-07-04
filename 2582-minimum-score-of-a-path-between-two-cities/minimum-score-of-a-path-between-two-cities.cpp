class Solution {
public:
    class dsu {
    public:
        vector<int> parent;
        vector<int> sz;

        dsu(int n) {
            parent.resize(n + 1);
            sz.resize(n + 1, 1);

            for (int i = 1; i <= n; i++) {
                parent[i] = i;
            }
        }

        int get_parent(int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = get_parent(parent[x]);
        }

        void union_by_sz(int x, int y) {
            int p1 = get_parent(x);
            int p2 = get_parent(y);

            if (p1 == p2)
                return;

            if (sz[p1] >= sz[p2]) {
                parent[p2] = p1;
                sz[p1] += sz[p2];
            } else {
                parent[p1] = p2;
                sz[p2] += sz[p1];
            }
        }
    };

    int minScore(int n, vector<vector<int>>& roads) {
        dsu d(n);

        // Union all roads
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            d.union_by_sz(u, v);
        }

        int ans = INT_MAX;
        int par = d.get_parent(1);

        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];

            if (d.get_parent(u) == par && d.get_parent(v) == par) {
                ans = min(ans, roads[i][2]);
            }
        }

        return ans;
    }
};