#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define F first
#define S second
ll n,m,x,y;
int a[205];
vector<pair<int,int>> E;
ll cst[205][205];
ll dist[205],INF = 999999999999999999;

void bellman()
{
    fill(dist,dist+n+4,INF);
    dist[0]=0;
    for(int i=0;i<n-1;i++)
    {
        for(auto x:E)
        {
            if(dist[x.F]<INF) dist[x.S]=min(dist[x.S],dist[x.F]+cst[x.F][x.S]);
        }
    }
}

int main()
{
    int $=1,tc=1;
    cin>>$;
    while($--)
    {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;x--;y--;
            ll b=a[y]-a[x];
            cst[x][y]=b*b*b;
            E.push_back({x,y});
        }
        bellman();
        cout<<"Case "<<tc++<<":\n";
        ll q;
        cin>>q;
        while(q--)
        {
            cin>>x;x--;
            if(dist[x]>=3&&dist[x]<INF)
                cout<<dist[x]<<endl;
            else cout<<"?"<<endl;
        }
    }

}


/*
8888888888888888888888888888
    Md. Masud Mazumder
    University of Chittagong
    Department of CSE
8888888888888888888888888888
*/
