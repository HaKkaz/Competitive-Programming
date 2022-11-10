#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define int long long
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define F first
#define S second
#define SZ(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = "  << x << '\n';
using namespace std;
int MN[1000050] , MX[1000050] , a[1000050];
signed main(){
	IOS;
	int n , k ; 
	while(cin >> n >> k ){
		for(int i=0 ; i<n ; ++i) cin >> a[i];
		deque<int> dq1 , dq2;
		for(int i=0 ; i<n ; ++i){
			while(dq1.size() and dq1.front() <= i-k) dq1.pop_front();
			while(dq1.size() and a[dq1.back()] >= a[i]) dq1.pop_back();
			dq1.push_back(i);
			if(i-k+1 >= 0){
				MN[i] = a[dq1.front()];
			}
		}
		
		for(int i=0 ; i<n ; ++i){
			while(dq2.size() and dq2.front() <= i-k) dq2.pop_front();
			while(dq2.size() and a[dq2.back()] <= a[i]) dq2.pop_back();
			dq2.push_back(i);
			if(i-k+1 >= 0){
				MX[i] = a[dq2.front()];
			}
		}
		if(k <= n){
			for(int i=k-1 ; i<n ; ++i) cout << MN[i] << " \n"[i+1==n];
			for(int i=k-1 ; i<n ; ++i) cout << MX[i] << " \n"[i+1==n];
		}
		else{
			cout << a[dq1.front()] << '\n';
			cout << a[dq2.front()] << '\n';	
		}
 	}
}