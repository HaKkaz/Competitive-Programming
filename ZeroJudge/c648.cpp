#include<bits/stdc++.h>
using namespace std;
long long plat[100005];
long long tot[100005];
void init(){
	fill(tot,tot+100005,0);
	tot[0] = 1e9;
}
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		init();
		int W , L ;
		cin >> W >> L;
		for(int i = 1 ; i < W ; i++){
			cin >> plat[i];
		}
		plat[W] = 1e9;
		int now = 0,pt = 1;
		
		while(now<W){
    if(pt==now) pt++;
            
				long long tmp = min( tot[now], plat[pt] );
				tot[now] -= tmp;
				tot[pt] += tmp;
				plat[pt] -= tmp;
        
				//for(int k=1;k<W;k++) cout<<plat[k]<<' ';
				//cout<<'\n';
				//for(int k=0;k<=W;k++) cout<<tot[k]<<' ';
				//cout<<'\n';
			if( !plat[pt] || pt==now ) pt++;
   if( pt>now+L || !tot[now] ) now++;
		}
		
		cout << tot[W] <<'\n';
	}
}
/*
	pt
	 1 2 3 4 5 6 7 8 9
	 0 0 2 0 1 0 0 2 1 MAXN
MAXN 0 0 0 0 0 0 0 0 0
now
*/