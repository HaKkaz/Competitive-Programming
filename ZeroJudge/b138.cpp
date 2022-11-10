#include<iostream>
using namespace std;
int main(){
    int ap[10];
    while(cin>>ap[0]){
        for(int i=1;i<10;++i) cin>>ap[i];
        int h; cin>>h;
        int cnt=0;
        for(int i=0;i<10;i++) if(ap[i]<=h+30) cnt++;
        cout<<cnt<<endl;
    }
}