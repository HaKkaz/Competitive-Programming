#include<bits/stdc++.h>
#define int long long
//#define test_
#define MP make_pair
#define pb push_back
#define S second
#define F first
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
using namespace std;
int a , b , res;
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> a >> b >> res;
	bool tag = 0;
	if(a) a=1;
	if(b) b=1;
	if((a and b) == res) cout << "AND\n" , tag = 1;
	if((a or b) == res) cout << "OR\n" , tag = 1;
	if((a xor b) == res) cout << "XOR\n" , tag = 1;
	if(not tag) cout << "IMPOSSIBLE\n";
}