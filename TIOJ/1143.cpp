#include <bits/stdc++.h>
#define F first
#define S second
#define int long long
#define rep( i , n ) for( int i = 0 ; i < (n) ; i++ )
#define endl cout << "\n"
#define all(x) (x).begin(), (x).end()
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define display(array, f, l) for (int index = (f); index < (l); ++index) cout << (array)[index] << " "

using namespace std;

bool check(int x, int y){
    if (x >= 0 && x<100 && y >=0 && y<100) return true;
    return false;
}

int dx[8] = {-3,-3,-1,1,3 ,3 ,1,-1};
int dy[8] = {-1 ,1 ,3,3,1,-1,-3,-3};
int cx[8] = {-1,-1, 0,0,1, 1, 0, 0};
int cy[8] = { 0, 0, 1,1,0, 0,-1,-1};

int n;
int met[105][105];
bool found = false;

void bfs(int stx,int sty){
    int xx, yy, nd;
    int chx, chy;
    met[stx][sty] = 1;
    queue<pair<pair<int,int>,int>> q;
    q.push({{stx,sty}, 0});
    while(q.size()){
        for(int i = 0;i<8;i++){

            xx = q.front().F.F + dx[i];
            yy = q.front().F.S + dy[i];
            chx = q.front().F.F + cx[i];
            chy = q.front().F.S + cy[i];
            nd = q.front().S + 1;

            if (!check(xx, yy)) continue;
            if (!check(chx,chy)){
                continue;
            }
            else if (met[chx][chy] == 2){
                continue;
            }
            //cout << met[q.front().F.F+1][q.front().F.S] << " " << xx << " " << yy << " " << nd <<"\n";
            if (met[xx][yy] == 3){
                if (met[xx][yy] == 3){
                    cout << nd << "\n";
                    exit(0);
                }

            }
            else if (met[xx][yy] == 0){
                q.push({{xx,yy } , nd});
                met[xx][yy] = 1;
            }
        }
        q.pop();
    }
}


signed main()
{
    //IOS;
    cin >> n;
    int a, b,stx,sty,tgx,tgy;
    for(int i = 0;i<n;i++){
        cin >> a >> b;
        met[a][b] = 2;
    }
    cin >> stx >> sty;
    cin >> tgx >> tgy;
    met[tgx][tgy] = 3;
    bfs(stx, sty);
    if (!found){
        cout << "impossible\n";
    }

}
