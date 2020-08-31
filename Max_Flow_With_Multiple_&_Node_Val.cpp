//Lightoj 1155
//Max Flow With Multiple Source and Node Val
//O(VE^2)

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
ll n,nodV,u,v,src,sink,m,b,d,c;
vector<ll>graph[210];
ll cap[210][210];
int par[210];

ll findpath()
{
    memset(par,-1,sizeof(par));
    par[src]=-2;
    queue<pair<ll,ll>>q;
    q.push({src,LLONG_MAX});
    while(!q.empty())
    {
        ll cur=q.front().first;
        ll flow=q.front().second;
        q.pop();

        for(auto nxt:graph[cur])
        {
            if(par[nxt]==-1 && cap[cur][nxt]>0)
            {
                flow=min(flow,cap[cur][nxt]);
                par[nxt]=cur;
                if(nxt==sink) return flow;
                q.push({nxt,flow});
            }
        }
    }
    return 0;
}

ll max_flow()
{
    ll ans=0;
    ll newFlow=0;
    while(newFlow=findpath())
    {
        ll cur=sink;
        ans+=newFlow;
        while(cur!=src)
        {
            ll prev=par[cur];
            cap[prev][cur]-=newFlow;
            cap[cur][prev]+=newFlow;
            cur=prev;
        }
    }
    return ans;
}

int main()
{
    int $=1,tc=1;
    cin>>$;
    while($--)
    {
        cin>>n;
        src=0;
        sink=2*(n+1);
        for(int i=0;i<=sink;i++) graph[i].clear();
        memset(cap,0,sizeof(cap));
        for(int i=1;i<=n;i++)
        {
            cin>>nodV;
            u=2*i-1;
            v=u+1;
            graph[u].pb(v);
            graph[v].pb(u);
            cap[u][v]+=nodV;
        }
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v>>c;
            u=2*u;
            v=2*v-1;
            graph[u].pb(v);
            graph[v].pb(u);
            cap[u][v]+=c;
        }
        cin>>b>>d;
        for(int i=1;i<=b;i++)
        {
            cin>>u;
            u=2*u-1;
            graph[src].pb(u);
            graph[u].pb(src);
            cap[src][u]+=LLONG_MAX;
        }
        for(int i=1;i<=d;i++)
        {
            cin>>v;
            v=2*v;
            graph[sink].pb(v);
            graph[v].pb(sink);
            cap[v][sink]+=LLONG_MAX;
        }
        ll ans=max_flow();
        cout<<"Case "<<tc++<<": "<<ans<<endl;
    }
}


/*
8888888888888888888888888888
    Md. Masud Mazumder
    University of Chittagong
    Department of CSE
8888888888888888888888888888
*/
