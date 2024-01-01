#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#include<bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define fast
#else
#define fast cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define cerr if(1); else cerr
#endif
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
using ll = long long;
using ld = long double;
using pii = pair<int,int>;

const int MAXN = 2005;
char s[MAXN][MAXN];
bool gg[MAXN][MAXN];
int ans[MAXN][MAXN];

bool block(char c) {
    return c == '#' || c == '>' || c == '<' || c == '^' || c == 'v';
}

int main() {
    int n, m;
    cin >> n >> m;
    int sx = -1, sy = -1;
    int ex = -1, ey = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> s[i][j];
            if (s[i][j] == 'S') {
                sx = i, sy = j;
            }
            if (s[i][j] == 'G') {
                ex = i, ey = j;
            }
            if (s[i][j] == '#') {
                gg[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        bool hav = 0;
        for (int j = 0; j < m; ++j) {
            if (block(s[i][j])) hav = 0;
            if (s[i][j] == '>') hav = 1;
            gg[i][j] |= hav;
        }
        hav = 0;
        for (int j = m-1; j >= 0; --j) {
            if (block(s[i][j])) hav = 0;
            if (s[i][j] == '<') hav = 1;
            gg[i][j] |= hav;
        }
    }
    
    for (int j = 0; j < m; ++j) {
        bool hav = 0;
        for (int i = 0; i < n; ++i) {
            if (block(s[i][j])) hav = 0;
            if (s[i][j] == 'v') hav = 1;
            gg[i][j] |= hav;
        }
        hav = 0;
        for (int i = n-1; i >= 0; --i) {
            if (block(s[i][j])) hav = 0;
            if (s[i][j] == '^') hav = 1;
            gg[i][j] |= hav;
        }
    }
    // for (int i = 0; i < n; ++i) {
        // for (int j = 0; j < m; ++j) {
            // cout << gg[i][j];
        // }
        // cout << '\n';
    // }

    queue<pii> q;
    q.emplace(sx, sy);
    ans[sx][sy] = 1;
    const int dx[]={1,-1,0,0};
    const int dy[]={0,0,1,-1};

    while(q.size()) {
        auto [x, y] = q.front();
        // cout << x << ' ' << y << '\n';
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && 
                    !gg[xx][yy] && !ans[xx][yy]) {
                q.emplace(xx, yy);
                ans[xx][yy] = ans[x][y] + 1;
            }
        }
    }
    cout << (ans[ex][ey] ? ans[ex][ey]-1 : -1) << '\n'; 
}
