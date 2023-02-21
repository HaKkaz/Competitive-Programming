class Solution {
public:
    vector< vector<int> > G;
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        G.resize(n);
        for (auto edge : roads) {
            int a = edge[0], b = edge[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        long long ans = 0;
        function<int(int, int)> dfs = [&](int now, int lst) {
            int subtree = 1;
            for (int &nxt : G[now]) {
                if (nxt == lst) continue;
                int sub = dfs(nxt, now);
                subtree += sub;
                ans += (sub + seats - 1) / seats;
            }
            return subtree;
        };

        dfs(0,0);

        return ans;
    }
};