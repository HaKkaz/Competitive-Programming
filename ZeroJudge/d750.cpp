#include<iostream>
#include<algorithm>
using namespace std;
int num[10005];
int n , m;
bool cmp(int a, int b){
	if(a%m != b%m) return (a%m)<(b%m);
	else{
		if(a%2 != b%2) return (a%2)>(b%2);
		else{
			if(a%2) return a>b;
			else return a<b;
		} 
	}
}
int main(){ios::sync_with_stdio(false),cin.tie(0);
	while(cin >> n >> m && n+m){
		for(int i=0 ; i<n ; ++i) cin >> num[i];
		sort(num,num+n,cmp);
		cout<<n<<' '<<m<<'\n';
		for(int i=0 ; i<n ; ++i) cout << num[i]<<'\n';
	}
	cout<<"0 0\n";
}