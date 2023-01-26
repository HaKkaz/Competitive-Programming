class Solution {
public:
    struct DSU {
        vector<int> fa, sz;
        vector< map<int,int> > cnt;
        int n, ans;
        DSU (int _n) {
            n = _n;
            ans = n;
            fa.resize(n);
            sz.resize(n,1);
            cnt.resize(n);
            for (int i = 0; i < n; ++i) {
                fa[i] = i;
            }
        }

        int Find(int x) {
            if (x == fa[x]) return x;
            return fa[x] = Find(fa[x]);
        }

        void Union(int a, int b, int val) {
            a = Find(a), b = Find(b);
            if (a == b) return;
            ans += cnt[Find(a)][val] * cnt[Find(b)][val];
            if (sz[a] < sz[b]) swap(a,b);
            fa[b] = a;
            sz[a] += sz[b];
            for (auto &[id, num] : cnt[b]) {
                cnt[a][id] += num;
            }
        }
    };
    
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        const int n = vals.size();
        vector<vector<int>> G(n,vector<int>());
        for (int i = 0; i < n - 1; ++i) {
            int a = edges[i][0];
            int b = edges[i][1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector< pair<int,int> > pr(n);
        for (int i = 0; i < n; ++i) {
            pr[i] = {vals[i], i};
        }
        sort(begin(pr), end(pr));

        DSU dsu(n);
        for (int i = 0; i < n; ++i) dsu.cnt[i][vals[i]] = 1;

        for (int i = 0; i < n; ++i) {
            auto [val, id] = pr[i];
            for (auto &adj : G[id]) {
                if (vals[adj] <= vals[id]) {
                    dsu.Union(adj, id, vals[id]);
                }
            }
        }
        return dsu.ans;
    }
};