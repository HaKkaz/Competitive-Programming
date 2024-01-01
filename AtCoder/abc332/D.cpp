// #pragma GCC ivdep // before loop
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


signed main() {
    fast;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr1(n, vector<int>(m));
    vector<vector<int>> arr2(n, vector<int>(m));
    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr1[i][j];
        }
    }

    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr2[i][j];
        }
    }

    vector<int> row_perm, col_perm;
    for (int i = 0; i < n; ++i) row_perm.push_back(i);
    for (int i = 0; i < m; ++i) col_perm.push_back(i);

    int ans = 1e9;
    do {
        do {
            vector<vector<int>> temp(n, vector<int>(m));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    temp[i][j] = arr1[row_perm[i]][col_perm[j]];
                }
            }
            if (temp == arr2) {
                int inv = 0;
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < i; ++j) {
                        if (row_perm[j] > row_perm[i]) ++inv;
                    }
                }
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < i; ++j) {
                        if (col_perm[j] > col_perm[i]) ++inv;
                    }
                }
                ans = min(ans, inv);
            }
        } while(next_permutation(ALL(col_perm)));
    }while(next_permutation(ALL(row_perm)));
    
    if (ans == 1e9) cout << -1 << endl;
    else cout << ans << '\n';
}