#include<bits/stdc++.h>
#define test_
#define pb push_back
#define S second
#define F first
#define Sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
#define endl cout<<'\n';
#define rep(i , n) for(int mm=i ; mm<n ; ++mm)
using namespace std;
int main(){
//__IO
	int n , cc=0;
	cin >> n >> ws;
	for(; cc < n ; ++cc){
		string str;
		char c;
		int cnt = 0 , cnt2 = 0 ;
		bool a = false , b = false;
		while((c = getchar()) != '\n'){
			str.pb(c);
			if(c == ' ') str.clear();
			if(str == "chi") ++cnt; 
			if(str == "tu") ++cnt2;
			if(cnt2 > cnt) b = 1;
		} 
		if(cnt > cnt2) a = 1;
		if(a == true && b == false) cout << "chi pu tao bu tu pu tao pi\n";
		else if(a ==false && b == true) cout << "bu chi pu tao dao tu pu tao pi\n";
		else if(a == true && b == true) cout <<  "chi pu tao bu tu pu tao pi, bu chi pu tao dao tu pu tao pi\n";
		else cout << "chi pu tao tu pu tao pi\n";	
		
	} 
}