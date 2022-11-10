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
	string s;
	int kase=1;
	while(cin >> s){
		if(s == "#") return 0;
		cout << "Case "<<kase++<<": ";
		if(s == "HELLO") cout << "ENGLISH\n";
		else if(s == "HOLA") cout << "SPANISH\n";
		else if(s == "HALLO") cout << "GERMAN\n";
		else if(s == "BONJOUR") cout << "FRENCH\n";
		else if(s == "CIAO") cout <<"ITALIAN\n";
		else if(s == "ZDRAVSTVUJTE") cout << "RUSSIAN\n";
		else cout << "UNKNOWN\n";
	}
}