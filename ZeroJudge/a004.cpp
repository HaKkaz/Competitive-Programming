#include<iostream>
using namespace std;
int main(){
	int y;
	while(cin>>y){
		if (( !(y%4) && (y%100) ) || !(y%400))	cout<<"閏年\n";
		else	cout<<"平年\n";
	}
}