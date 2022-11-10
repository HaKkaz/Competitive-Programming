#include<bits/stdc++.h>
using namespace std;
int cnt[10000000];
int main(){
	int n;
	while(cin >> n){
		fill(cnt,cnt+10000000,0);
		int N = n;
		for(int i=2 ; i<=N ;){
			if(n == 0) break;
			if((n%i) == 0 ) cnt[i]++,n/=i;
			else i++;
		}
		bool ok=true;
		for(int i=2; i<=N ; i++){
			if(cnt[i]){
				if(!ok) cout<<" * ";
				ok=false;
				cout << i ;
				if(cnt[i]>1) cout << "^" << cnt[i];
			}
		}
		cout<<'\n';
	}
}