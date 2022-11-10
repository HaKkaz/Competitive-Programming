#include<bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	vector<int> v ,v2;
	int n,k,x,ans=0,tmp,i;
	cin>>n>>k;
	for(i=0;i<n;v.push_back(x),++i) cin>>x;
	for(i=0;i<n;v2.push_back(x),++i) cin>>x;
	for(i=0;i<n;++i){if(v[i]!=v2[i]&&i+k>n){cout<<0<<'\n';return 0;}if(v[i]==v2[i]) continue;else{(v[i]>v2[i])?(tmp=9-abs(v2[i]-v[i])):(tmp=abs(v2[i]-v[i])),ans+=abs(tmp);for(int j=i;j<i+k;++j) (v[j]=(v[j]+tmp)%9)==0?v[j]=9:v[j];}}
	cout<<ans<<'\n';
}