#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define int long long
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
signed main(){
	IOS;
	int t=1;
	cin >> t;
	while(t--){
		int n; cin >> n ;
		string str; 
		const int maxn = 105;
		int tmp[maxn];
		int top = 1 , now = 0;
		while(n--){
			int x;
			cin >> str;
			if(str == "RIGHT"){
				tmp[top++] = 1;
				now++;
			}
			if(str == "LEFT"){
				tmp[top++] = -1;
				now--;
			}
			if(str == "SAME"){
				cin >> str >> x;
				now += tmp[x];
				tmp[top++] = tmp[x];
			}
		}
		cout<< now << '\n';
	}
}