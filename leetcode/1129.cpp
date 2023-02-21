class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        const int maxn = 105;
        const int inf = 1e9;
        vector<int> G[2][maxn];
        vector<vector<int>> dis(2, vector<int>(n,inf));

        for (int i = 0; i < redEdges.size(); ++i) {
            int a = redEdges[i][0];
            int b = redEdges[i][1];
            G[0][a].push_back(b);
        }

        for (int i = 0; i < blueEdges.size(); ++i) {
            int a = blueEdges[i][0];
            int b = blueEdges[i][1];
            G[1][a].push_back(b);
        }

        queue< pair<int,int> > q;
        q.emplace(0,0), q.emplace(0,1);
        dis[0][0] = dis[1][0] = 0;

        while(q.size()) {
            auto [now, color] = q.front();
            q.pop();

            for (int &nxt : G[color ^ 1][now]) {
                if (dis[nxt][color ^ 1] == inf) {
                    dis[nxt][color ^ 1] = dis[now][color] + 1;
                    q.emplace(nxt, color ^ 1);
                }
            }
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = min(dis[i][0], dis[i][1]);
            if (ans[i] == inf) ans[i] = -1;
        }
        return ans;
    }
};