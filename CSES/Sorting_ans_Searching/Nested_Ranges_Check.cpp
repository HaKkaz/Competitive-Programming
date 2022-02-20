#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;

const int maxn = 200050;
int ans1[maxn] , ans2[maxn];
struct T{
    int l,r,id;  
    bool operator<(const T &x)const{
        return l == x.l ? r > x.r : l < x.l;
    }
}seg[maxn];

int bit[maxn];

void upd(int i){
    for( ; i<maxn ; i+=(i&-i))
        bit[i]++;
}

int qry(int i){
    int ret = 0;
    for( ; i ; i-=(i&-i))
        ret += bit[i];
    return ret;
}


signed main(){

    vector<int> R;
    int n; cin >> n;
    for(int i=0 ; i<n ; ++i){
        cin >> seg[i].l >> seg[i].r , seg[i].id = i;
        R.emplace_back(seg[i].r);
    }

    sort(ALL(R)) , R.resize(unique(ALL(R))-R.begin());

    for(int i=0 ; i<n ; ++i){
        seg[i].r = upper_bound(ALL(R) , seg[i].r) - R.begin();
    }

    sort(seg , seg+n);

    for(int i=0 ; i<n ; ++i){
        int r = seg[i].r , id = seg[i].id;
        int ret = i - qry(r-1);
        ans2[id] = ret;
        upd(r);
    }

    for(int i=1 ; i<maxn ; ++i) bit[i]=0;

    for(int i=n-1 ; i>=0 ; --i){
        int r = seg[i].r , id = seg[i].id;
        int ret = qry(r);
        
        ans1[id] = ret;
        upd(r);
    }
    
    for(int i=0 ; i<n ; ++i) cout << ans1[i] << " \n"[i+1==n];
    for(int i=0 ; i<n ; ++i) cout << ans2[i] << " \n"[i+1==n];
}

