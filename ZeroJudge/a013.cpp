#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
bool type;
int f(char c,char d)
{
	type=0;
	if(c=='C'&&d=='M') {type=1;return 900;}
	if(c=='C'&&d=='D') {type=1;return 400;}
	if(c=='X'&&d=='C') {type=1;return 90;}
	if(c=='X'&&d=='L') {type=1;return 40;}
	if(c=='I'&&d=='X') {type=1;return 9;}
	if(c=='I'&&d=='V') {type=1;return 4;}
	if(c=='I') return 1;
	if(c=='V') return 5;
	if(c=='X') return 10;
	if(c=='L') return 50;
	if(c=='C') return 100;
	if(c=='D') return 500;
	if(c=='M') return 1000;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	string sa,sb;
	while(cin>>sa)
	{
		if(sa=="#") break;
		cin>>sb;
		int a=0,b=0;
		for(int i=0;i<sa.size();++i)
		{
			if(i!=sa.size()-1){
				a+=f(sa[i],sa[i+1]);
				if(type) i++;
			}
			else{
				a+=f(sa[i],' ');
			}
		}
		for(int i=0;i<sb.size();++i)
		{
			if(i!=sb.size()-1){
				b+=f(sb[i],sb[i+1]);
				if(type) i++;
			}
			else{
				b+=f(sb[i],' ');
			}
		}
		int x=abs(a-b);
		//cout<<a<<' '<<b<<endl;
		if(x==0) cout<<"ZERO";
			while(x>=1000) cout<<"M",x-=1000;
			if(x>=900) cout<<"CM",x-=900;
			if(x>=500) cout<<"D",x-=500;
			if(x>=400) cout<<"CD",x-=400;
			while(x>=100) cout<<"C",x-=100;
			if(x>=90) cout<<"XC",x-=90;
			if(x>=50) cout<<"L",x-=50;
			if(x>=40) cout<<"XL",x-=40;
			while(x>=10) cout<<"X",x-=10;
			if(x>=9) cout<<"IX",x-=9;
			if(x>=5) cout<<"V",x-=5;
			if(x>=4) cout<<"IV",x-=4;
			while(x>=1) cout<<"I",x-=1;
		cout<<endl;
	}

}