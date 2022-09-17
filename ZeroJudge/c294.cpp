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

int a[10005];
signed main(){
	IOS;
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a,a+3);
	cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
	if(a[0]+a[1] < a[2]) cout << "No\n";
	else if(a[0]*a[0] + a[1]*a[1] < a[2]*a[2]) cout << "Obtuse\n";
	else if(a[0]*a[0] + a[1]*a[1] == a[2]*a[2]) cout << "Right\n";
	else if(a[0]*a[0] + a[1]*a[1] > a[2]*a[2]) cout << "Acute\n";
}