class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();
        
        vector< vector<int> > dis(n, vector<int>(m,-1));
        pair<int,int> q[10005];
        int l = 0, r = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                   q[++r] = {i, j}; 
                   dis[i][j] = 0;
                }
            }
        }

        int ans = 0;
        const int dx[] = {1,-1,0,0};
        const int dy[] = {0,0,1,-1};
        while(r-l+1) {
            auto &[x, y] = q[l++];
            for (int d = 0; d < 4; ++d) {
                int xx = x + dx[d];
                int yy = y + dy[d];
                if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
                if (dis[xx][yy] == -1 && !grid[xx][yy]) {
                    q[++r] = {xx, yy}; 
                    dis[xx][yy] = dis[x][y] + 1;
                    ans = max(ans, dis[xx][yy]);
                }
            }
        }
        return ans ? ans : -1;
    }
};