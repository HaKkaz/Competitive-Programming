#include<bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> fa;
    DSU(int _n){
        fa.resize(_n+1);
        for(int i=1 ; i<=_n ; ++i) fa[i] = i;
    }
    int Find(int x){
        if(x == fa[x]) return x;
        return fa[x] = Find(fa[x]);
    }
    void Union(int a , int b){
        a = Find(a) , b = Find(b);
        if(a == b) return;
        fa[b] = a;
    }
    bool same(int a , int b){
        return Find(a) == Find(b);
    }

};

int main(){
    int n , m;
    while(cin >> n >> m ){
        DSU dsu(n);
        while(m--){
            int a,b; cin >> a >> b;
            a = dsu.Find(a);
            b = dsu.Find(b);
            if(a > b) swap(a,b);
            dsu.Union(a,b);
        }
        int k; cin >> k;
        cout << dsu.Find(k) << '\n';
    }
}