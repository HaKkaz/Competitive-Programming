#include <bits/stdc++.h>
#define F first
#define S second
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl cout << "\n"

using namespace std;

int met[3005][3005];
bool walked[3005][3005];
int t;
int k;

int n,xa,ya,za,xb,yb,zb;

bool check(int x, int y, int z){
    if (x >= 0 && x <= n && y >= 0 && y <= n && z >= 0 && z <= n) return true;
    return false;
}

void bfs(int stx, int sty){
    walked[stx][sty] = 1;
    queue<pair<pair<int,int>,int>> q;
    q.push({{stx,sty},k - (stx+sty)});

    while(!q.empty()){


        int nx = q.front().F.F;
        int ny = q.front().F.S;
        int nz = q.front().S;

        q.pop();

        if (!walked[ny][nx]) q.push({{ny,nx},nz }), walked[ny][nx] = 1;
        if (!walked[nx][nz]) q.push({{nx,nz},ny }), walked[nx][nz] = 1;
        if (!walked[nz][ny]) q.push({{nz,ny},nx }), walked[nz][ny] = 1;

        if (check(2*ny-nx+1,2*nx-ny-1,nz) && !walked[2*ny-nx+1][2*nx-ny-1]) q.push({{2*ny-nx+1,2*nx-ny-1},nz }), walked[2*ny-nx+1][2*nx-ny-1] = 1;



    }
}

signed main(){

    IOS;
    while(true){

        cin >> n >> xa>>ya>>za>>xb>>yb>>zb;
        if (n == 0) return 0;
        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=n;j++){
                walked[i][j] = 0;
            }
        }

        k = xa + ya + za;

        if (xa + ya + za != xb + yb + zb) cout << "No\n";
        else if (bfs(xa,ya), walked[xb][yb] == 1) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}