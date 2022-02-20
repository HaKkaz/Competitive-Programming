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

const int maxn = 1e6+60;
int bit[maxn];

void upd(int i , int v){
    for( ; i < maxn ; i+=(i&-i))
        bit[i]+=v;
}

int qry(int i){
    int ret=0;
    for( ; i ; i-=(i&-i))
        ret += bit[i];
    return ret;
}

int kth(int k){
    int ret = 0 , now = 0;
    for(int i=18 ; i>=0 ; --i){
        if(ret + bit[now | (1<<i)] < k){
            ret += bit[now | (1<<i)];
            now |= (1<<i);
        }
    }
    return now;
}

signed main(){
    // fast;
    int n,k;
    cin >> n >> k ;
    ++k;
    for(int i=1 ; i<=n ; ++i) upd(i,1);
    int now = 0;
    for(int i=n ; i>=1 ; --i){
        int hav = qry(now);
        int ret = kth((k+hav+(i-1))%i+1)+1;
        upd(ret,-1);
        now = ret;
        cout << ret << ' ';
    }
}

