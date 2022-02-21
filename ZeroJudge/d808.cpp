# include<bits/stdc++.h>
using namespace std;
int fa[1000005];

int find(int x)
{
    if(x==fa[x]) return x;
    fa[x]=find(fa[x]);
    return fa[x];
}

void Union(int a,int b)
{
    a=find(a),b=find(b);
    if(a==b) return;
    fa[b] = a;
}


int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    int n;
    while(cin>>n)
    {
        for(int i=1;i<=n;++i)
        {
            fa[i]=i;
        }
        int x;
        for(int i=1;i<=n;++i)
        {
            cin>>x;
            Union(i,x); 
        }
        
        int ct=0;
        vector<int> ans(n+1,0);
        for(int i=1;i<=n;i++)
        {
            ans[find(i)]++;
            if(find(i)==i) {
                ct++;
            }
        }
        
        cout << ct << ' '<< *max_element(ans.begin() , ans.end()) << endl;
    }
}