#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define S second
#define F first
#define sz(x) (int)(x).size()
#define rz(n) resize(n)
#define all(x) (x).begin(),(x).end()
#define IOS ios::sync_with_stdio(false),cin.tie(0);
#define pii pair<int,int>
#define endl cout<<'\n';
#define LINE cout << "-----------------------\n";
using namespace std;
const int inf = numeric_limits<int>::max();
const int maxn = 1e6+500;
int m;
int f(int n , int k){
	if(k==0) return 0;
	return (f(n-1 , k-1)+m)%n;
}
signed main(){
	IOS;
	int n , k;
	cin >> n >> m >> k;
	cout << f(n , k)+1 << '\n';
}

//same problem as Josephus problem