class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        for (int i = 0; i < n/2 + (n&1); ++i) {
            for (int j = 0; j < n/2; ++j) {
                int xx,yy,x = i, y = j, tmp = matrix[i][j];
                xx = n-y-1, yy = x;
                matrix[x][y] = matrix[xx][yy];
                x = xx, y = yy;
                
                xx = n-y-1, yy = x;
                matrix[x][y] = matrix[xx][yy];
                x = xx, y = yy;

                xx = n-y-1, yy = x;
                matrix[x][y] = matrix[xx][yy];
                x = xx, y = yy;

                matrix[x][y] = tmp;
            }
        }
    }
};