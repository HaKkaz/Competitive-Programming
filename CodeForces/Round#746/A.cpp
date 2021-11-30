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
    int t = 1;
    cin >> t;
    while(t--){
        int n, h; cin >> n >> h;
        vector<int> a(n);
        for(int &x : a) cin >> x;
        sort(ALL(a));
        int A = a.back(); a.pop_back();
        int B = a.back();
        cout << (h / (A+B))*2 + (h%(A+B) > A ? 2 : (h%(A+B)>0)) << '\n';

    }

}

