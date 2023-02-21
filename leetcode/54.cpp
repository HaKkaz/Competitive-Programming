class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        const int m = matrix[0].size();
        int x = 0, y = 0;
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        int dd = 0;

        vector< vector<bool> > vis(n, vector<bool>(m,false));
        vector<int> ans;
        for (int tt = 0; tt < n * m; ++tt) {
            vis[x][y] = 1;
            ans.push_back(matrix[x][y]);
            int xx = x + dx[dd];
            int yy = y + dy[dd];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m || vis[xx][yy]) {
                dd = (dd + 1) % 4;
            }
            xx = x + dx[dd];
            yy = y + dy[dd];
            x = xx;
            y = yy;
        }
        return ans;
    }
};