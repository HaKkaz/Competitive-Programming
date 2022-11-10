#include<bits/stdc++.h>
using namespace std;
bool check[50000];
int main(){
	int n,k; cin>>n>>k;
 int tot=0;
	int price[n]; 
    for(int i=0;i<n;i++){ 
        cin>>price[i];
        tot+=price[i];
    }
	check[0]=1;
	
	//cout<<check[69]<<endl;
	
	for(int j=n-1;j>=0;j--){
		for(int i=tot;i>=0;i--){
			if(check[i-price[j]]&&(i-price[j])>=0) 
				check[i]=1;
		}
	}
	int MID=tot/2;
	for(int i=MID;i>=0;i--) 
		if(check[i]) {
			cout<<i<<" "<<tot-i<<endl;
			break;
	}
}