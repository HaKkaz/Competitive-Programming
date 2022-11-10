#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define int long long
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = "  << x << '\n';
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
//
bool num[10];
signed main(){
	IOS;
	for(int i=0 ; i<9 ; ++i){
		int x,y; cin >> x >> y;
		if(x > 0 && x < 10 && y > 20 && y < 30) num[1]=1;
		if(x > 10 && x < 20 && y > 20 && y < 30) num[2]=1;
		if(x > 20 && x < 30 && y > 20 && y < 30) num[3]=1;
		//
		if(x > 0 && x < 10 && y > 10 && y < 20) num[4]=1;
		if(x > 10 && x < 20 && y > 10 && y < 20) num[5]=1;
		if(x > 20 && x < 30 && y > 10 && y < 20) num[6]=1;
		//
		if(x > 0 && x < 10 && y > 0 && y < 10) num[7]=1;
		if(x > 10 && x < 20 && y > 0 && y < 10) num[8]=1;
		if(x > 20 && x < 30 && y > 0 && y < 10) num[9]=1;
	}
	int line = 0 , cnt = 0;
	if(num[1] and num[2] and num[3]) ++line;
	if(num[4] and num[5] and num[6]) ++line;
	if(num[7] and num[8] and num[9]) ++line;
	if(num[1] and num[4] and num[7]) ++line;
	if(num[2] and num[5] and num[8]) ++line;
	if(num[3] and num[6] and num[9]) ++line;
	//
	if(num[5]) cnt += 2;
	cnt += (num[2]+num[4]+num[6]+num[8])*5;
	cnt += (num[1]+num[3]+num[7]+num[9])*8;
	cout << line << ' ' << cnt << '\n';
}