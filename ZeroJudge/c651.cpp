#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
using namespace std;
const int MAXN=1e6+5;
int BIT[MAXN] , num[MAXN] , n , x , q;
inline void update(int k , int val){
	for(int i=k ; i<=n ; i+=lowbit(i)){
		BIT[i] ^= val;
	}
}
inline int getsum(int l , int r){
	--l;
	int suml = 0 , sumr = 0;
	for(int i=r ; i ; i-=lowbit(i)) sumr ^= BIT[i];
 	for(int i=l ; i ; i-=lowbit(i)) suml ^= BIT[i];
 	return sumr ^ suml;
}
void get_int(int &t){
	char c;
	while((c=getchar_unlocked())<'0');
	t=c^'0';
	while((c=getchar_unlocked())>='0') t*=10,t+=c^'0';
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	get_int(n),get_int(q);
	for(int i=1 ; i<=n ; i++){
		get_int(x);
		num[i] = x;
		update(i,x);
	}
	while(q--){
		int a , b , c;
		get_int(a),get_int(b),get_int(c);
		if(a == 0){
			cout << getsum(b , c) << '\n';
		}
		else{
			update(b , num[b]^c);
			num[b] = c;
		}
	}
}
/*
8
1 5 7 2 3 8 9 7
*/