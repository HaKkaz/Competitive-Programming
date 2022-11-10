#include<bits/stdc++.h>
#define pt first
#define dir second
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; 
	cin >> T;
	while(T--)
	{
		vector<pair <int,int> > p;
		int n,x,v;
		cin >> n >> x >> v;
		
		for(int i=0 ; i<n ; i++){
			int a,b;
			cin >> a >> b;
			p.push_back( {a,b} );
		}
		
		for(int i=0 ; i<n ; i++){
			if(p[i].dir == 0) p[i].pt = (p[i].pt+(v%x))%x;		
			else p[i].pt = (p[i].pt-(v%x)+x)%x;
		}
		sort(p.begin(),p.end());
		
		int ans=0;
		for(int i=0 ; i<n-1 ; i++){
			ans = max( ans , p[i+1].pt-p[i].pt );
		}
		ans = max( (x-p[n-1].pt)+(p[0].pt) , ans );
		cout << ans << '\n';
	}
}