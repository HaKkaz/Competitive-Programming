#include<bits/stdc++.h>
using namespace std;
bool prime[20000000];
const unsigned long long  MAXN = 20000000;
vector<int> p;
void seive(){
	fill(prime,prime+MAXN,1);
	for(int i=2;i*i<MAXN;i++)
	{
		for(int j=i*i;j<MAXN;j+=i)
		{
			prime[j]=false;
		}
	}
	for(int i=2 ; i<20000000 ; ++i){
		if(prime[i]) p.push_back(i);
	}
}
int main(){
	unsigned long long n;
	seive();
	while(cin >> n){
		unsigned long long  ans=0;
		for(int i=0 ; i<p.size() ; ++i){
			while(n%p[i]==0) ans+=p[i] , n /= p[i];
		}
		cout << (n==1?ans:n) <<'\n';
	}
}