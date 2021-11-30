#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define _ <<' '<<

vector<int> psum(100050,0);
void build(){
    for(int i=1 ; i<=100000 ; ++i){
        int cnt = __builtin_popcount(i); 
        bool prime = true;
        for(int j=2 ; j*j<=cnt ; ++j){
            if(cnt % j == 0) prime = 0;
        }
        if (cnt == 1) prime = 0;
        psum[i] += psum[i-1] + prime;
        // if (i < 10) cerr _ i _ cnt _ prime _ psum[i] _ endl;
    }
}

int main()
{
    int t; cin >> t;
    build();
    while(t--){
        int l , r; cin >> l >> r;
        if(l == 0) cout << psum[r] << '\n';
        else cout << psum[r] - psum[l-1] << '\n';
    }
}
