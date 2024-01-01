#include <iostream>
using namespace std;

bool vis[16];
long long ans = 0;
long long D[16][16];
int n;

void dfs(long long sum) {
    ans = max(ans, sum);
    int i = -1;
    for (int k = 0; k < n; ++k) {
        if (vis[k] == 0){ 
            i = k;
            break;
        }
    }
    if (i == -1) return;
    vis[i] = 1;
    dfs(sum);
    vis[i] = 0;
    for (int j = i+1; j < n; ++j) {
        if (vis[j] == 0) {
            vis[i] = vis[j] = 1;
            dfs(sum + D[i][j]);
            vis[i] = vis[j] = 0;
        }
    }
}

int main () {
    cin >> n ;
    for (int i = 0; i < n ; ++i) {
        for (int j = i+1; j < n; ++j) {
            cin >> D[i][j];
        }
    }
    dfs(0);
    cout << ans << '\n';
}
