#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define cerr if(0);else cerr
#define _ << ' ' << 
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
using ll = long long ;
using ld = long double ;
using pii = pair<int,int> ;

signed main(){
	fast;
    int n;
    for(n = 2 ; n<=8 ; ++n){
        map<int,int> v;
        cerr _ "----------------" _ endl;
        cerr _ n _ endl;
        vector<int> a(n);
        iota(ALL(a) , 1);
        vector<int> b = a;
        do{
            vector<int> c(n);
            iota(ALL(c) , 1);
            int cnt=0;
            do{
                ++cnt;
                vector<int> tmp(n);
                for(int i=0 ; i<n ; ++i){
                    tmp[b[i]-1] = c[i];
                }
                // cerr _ "c = "; for(int &x : c) cout << x << ' ';
                // cerr _ endl;
                c = tmp;
            }while(a != c) ;
            v[cnt]++;
            // cout << cnt << ' ';
        }while(next_permutation(ALL(b)));
        for(auto [num,cnt]:v) cout _ num _ cnt _ endl;
    }

    ;
}

