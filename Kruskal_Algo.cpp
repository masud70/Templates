#include<bits/stdc++.h>
using namespace std;

class edge
{
public:
    int source;
    int dest;
    int weight;
};

bool compare(edge e1,edge e2)
    {return e1.weight<e2.weight;}

int findparent(int n,int *parent)
    {
        if(parent[n]==n) return n;
        else return findparent(parent[n],parent);
    }

void kruskals(edge *input,int n,int e)
{
    sort(input,input+e,compare);
    edge *output=new edge[n-1];
    int cnt=0,i=0,ans=0;
    int *parent=new int[n];
    for(i=0;i<n;i++) parent[i]=i;i=0;
    while(cnt!=n-1)
    {

        int sp=findparent(input[i].source,parent);
        int dp=findparent(input[i].dest,parent);
        if(sp!=dp){ans+=input[i].weight;output[cnt++]=input[i];parent[sp]=dp;}
        i++;
    }
    for(int i=0;i<n-1;i++)
        cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
    cout<<"Coast of minimum spanning tree is = "<<ans;
}

int main()
{
    int n,e;
    cin>>n>>e;
    edge *input=new edge[e];
    int s,d,w;
    for(int i=0;i<e;i++)
        cin>>s>>d>>w,input[i].source=s,input[i].dest=d,input[i].weight=w;
    kruskals(input,n,e);
}
