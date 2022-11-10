#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;  
    while(cin>>n){
		int cnt=0;
		for(int i=3;i<=n;i++)  cnt+=(i-2);
		cout<<(n+cnt)*2<<endl;
	}
}