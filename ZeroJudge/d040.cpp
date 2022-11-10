#include <iostream>
#include <cstdio>
using namespace std;

struct P{
    double a,b;
    double c;
}p[100001];

int main(){
    int T,Min;
    while(cin>>T && T){
        Min = 0;
        for(int i=0;i<T;i++){
            cin>>p[i].a>>p[i].b;
            if(p[i].a<p[i].b)   swap(p[i].a,p[i].b);
            if(p[i].b*4<=p[i].a)    {
                p[i].c = p[i].b;
            }
            else{
                p[i].c=max(p[i].b/2,p[i].a/4);
            }
            if(p[i].c>p[Min].c)  Min = i;
        }
        cout<<Min+1<<endl;
    }
}