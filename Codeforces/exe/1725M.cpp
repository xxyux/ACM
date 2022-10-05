//
// Created by Xiangrui Yu on 2022/10/5.
//
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include"bits/stdc++.h"
using namespace std;
//#define int long long
#define INF 1000000000000000000LL
typedef long long LL;

const int N = 200010;
const int M = 600010;
int h[N],e[M],ne[M],f[M],idx=0;
void add(int x,int y,int z) {
    e[idx]=y;
    f[idx]=z;
    ne[idx]=h[x];
    h[x]=idx++;
}
int n,m;
LL d[N];
int in[N];

void dij() {
    priority_queue<pair<LL,int>,vector<pair<LL,int>>,greater<pair<LL,int>> > q;
    //memset(d,0x3f,sizeof(d));
    fill(d+1,d+2*n+1,INF);
    d[1]=0;
    q.push({0,1});
    while(!q.empty()) {
        int x=q.top().second;
        q.pop();
        if(in[x]) continue;
        in[x]=1;
        for(int i=h[x];~i;i=ne[i]) {
            int y=e[i];
            int z=f[i];
            if(d[y]>d[x]+z) {
                d[y]=d[x]+z;
                if(in[y]==0) q.push({d[y], y});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    while(m--) {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        add(n+y,n+x,z);
    }
    for(int i=1;i<=n;i++) add(i,i+n,0);
    dij();
    for(int i=2;i<=n;i++) {
        if(d[i+n]>=INF) d[i+n]=-1;
        cout<<d[i+n]<<" ";
    }
}