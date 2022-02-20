#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define cerr if(1);else cerr
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
using ll = long long;
using ld = long double;
using pii = pair<int,int>;

signed main(){
    fast;
    int n,m ; cin >> n >> m;
    vector<int> pos(n+2,0) , a(n+2) , add(n+2,0);
    int ans = 0 ;
    for(int i=1 ; i<=n ; ++i){
        cin >> a[i];
        if(!pos[a[i]-1]) ++ans , add[a[i]]=1;
        pos[a[i]] = i;
    }
    pos[0] = 1000000000;
    pos[n+1] = 1000000000;

    // cout << "ans = " << ans << endl;
    for(int i=0 ; i<m ; ++i){
        int x,y; cin >> x >> y;
        int X = a[x] , Y = a[y];

        if(add[X]) add[X] = 0 , --ans;
        if(add[X+1]) add[X+1] = 0 , --ans;
        if(add[Y]) add[Y] = 0 , --ans;
        if(add[Y+1]) add[Y+1] = 0 , --ans;

        swap(pos[a[x]] , pos[a[y]]);
        swap(a[x] , a[y]);

        if(pos[X-1] > pos[X] and !add[X]) add[X] = 1 , ++ans;
        if(pos[X] > pos[X+1] and !add[X+1]) add[X+1] = 1 , ++ans;
        if(pos[Y-1] > pos[Y] and !add[Y]) add[Y] = 1 , ++ans;
        if(pos[Y] > pos[Y+1] and !add[Y+1]) add[Y+1] = 1 , ++ans;

        // cout << "X = " << X << ' ' << "Y = " << Y << endl;
        // cout << "a = ";
        // for(int i=1 ; i<=n ; ++i) cout << a[i] << ' ' ;
        // cout << endl;
// 
        // cout << "pos = ";
        // for(int i=1 ; i<=n ; ++i) cout << pos[i] << ' ' ;
        // cout << endl;
// 
        cout << ans << '\n';
    }


}

