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
char ch[8][8];
bool has[8] , has1[20] , has2[50];
int ans = 0 ;

bool valid(int x , int y){
    return (x >= 0 && x < 8 && y >= 0 && y < 8) 
        and ch[x][y] == '.'
        and !has[x]
        and !has1[x+y]
        and !has2[x-y+20];
}


void solve(int y){
    if(y == 8){
        ans++;
        return;
    }
    for(int x = 0 ; x < 8 ; ++x){
        if(valid(x,y)){
            ch[x][y] = 'Q';
            has[x] = has1[x+y] = has2[x-y+20] = true;
            solve(y+1);
            ch[x][y] = '.';
            has[x] = has1[x+y] = has2[x-y+20] = false;
        }
    }

}

signed main(){
    fast;
    for(int i=0 ; i<8 ; ++i)
        for(int j=0 ; j<8 ; ++j)
            cin >> ch[i][j];
    solve(0);
    cout << ans << '\n';
}

