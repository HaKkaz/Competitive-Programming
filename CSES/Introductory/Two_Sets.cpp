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
    int n; cin >> n;
    set<int> A,B;
    int tot = (n+1)*n/2;
    if(tot&1) cout << "NO\n";
    else if(n == 3){
        cout << "YES\n2\n1 2\n1\n3\n";
    }
    else{
        for(int i=1 ; i+3<=n ; i+=4){
            A.insert(i);
            A.insert(i+3);
            B.insert(i+1);
            B.insert(i+2);
        }
        if(n%4==3){
            int x = n-1;
            if(A.find(x/2) == A.end()) swap(A,B);
            A.erase(x/2) , B.insert(x/2);
            A.insert(n) , A.insert(n-2);
            B.insert(x/2) , B.insert(n-1);
        }
        cout << "YES\n";
        cout << A.size() << '\n';
        for(int i : A) cout << i << ' ' ;
        cout << '\n';
        cout << B.size() << '\n';
        for(int i : B) cout << i << ' ' ;
        cout << '\n';
    }
}

