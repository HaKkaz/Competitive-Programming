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
#define int long long
const int maxn = 2e5+50;
int T[maxn];
bool has[maxn];
vector<int> need[maxn];
    
signed main(){
	fast;

    int n; cin >> n ;
    has[n] = 1;
    for(int i=1 ; i<=n ; ++i){
        cin >> T[i];
        int k; cin >> k ;
        for(int j=0 ; j<k ; ++j){
            int from; cin >> from;
            need[i].push_back(from);
        }
    }
    for(int i=n ; i>=1 ; --i){
        for(int &from : need[i]){
            has[from] |= has[i];
        }
    }
    int ret = 0  ;
    for(int i=1 ; i<=n ; ++i) ret += has[i] * T[i];
    cout << ret << '\n';
    ;
}

