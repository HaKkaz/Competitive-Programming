#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define ft first
#define sd second
#define ALL(v) v.begin(),v.end()
#define fast ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define cerr if(0);else cerr
#define _ << ' ' << 

int main(){
	fast;
    int t; cin >> t;
    while(t--){
        int n , x;
        cin >> n >> x;
        vector<int> a(n),b;
        for(int &c : a) cin >> c;
        b = a;
        sort(ALL(b));
        bool ok = true;
        for(int i=0 ; i<n ; ++i){
            if(i - x < 0 && i + x >= n && a[i] != b[i]) ok = false;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}

