#include<iostream>
#include<math.h>
#include<sstream>
#include<string.h>
#include<vector>
#include<bitset>
#pragma GCC optimize ("Ofast")
#define pb push_back
#define mp make_pair
#define Sz(x) (int)(x).size()
#define pii pair<int,int>
#define all(X) (X).begin(),(X).end()
#define F first
#define S second
#define endl cout<<'\n';
#define __IO ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int maxn = 10000000;
int x;
string str;
bitset<10000006> p;
inline void seive(){
	for(int i=2; i*i<=maxn ; ++i)
		for(int j=i*i ; j<=maxn ; j+=i)
			p[j] = 1;
	p[1]  = p[0]  = 1;
}

int main(){__IO
	seive();
	while(getline(cin , str)){
		long long ans = 0 , sum = 0 , last = -1;
		vector<int> num;
		stringstream ss;
		ss << str;
		while(ss >> x){
			num.push_back(x);
		}
		for(int i=0 ; i<Sz(num) ; ++i){
			if(p[num[i]] == 0 && num[i] != last && num[i] > last ) sum += num[i] , last = num[i];
			else{
				last = num[i];
				ans = max(ans , sum);
				if(p[num[i]] == 0) sum = num[i];
				else sum = 0;
			}
		}
		ans = max(ans , sum);
		cout << ans << '\n';
	}
}