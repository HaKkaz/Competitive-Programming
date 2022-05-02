#include <iostream>
#include <map>
#include <set>
using namespace std;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    multiset <pair <int,int>> have_handed;
    for (int i=0 ; i < m ; i++)
    {
        int a,b;
        cin >> a >> b;
        have_handed.insert(make_pair(min(a,b),max(a,b)));

    }
    for(int i=0; i<q ;i++)
    {
        int a,b;
        cin >> a >> b;
        if (have_handed.find(make_pair(min(a,b),max(a,b)))!=have_handed.end())
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
}
