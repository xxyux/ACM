//
// Created by Xiangrui Yu on 2022/8/6.
//

#include<bits/stdc++.h>
using namespace std;

const int N=2000010,M=4000010;
int h[N],e[M],ne[M],idx=0;
void add(int x,int y) {
    e[idx]=y;ne[idx]=h[x];h[x]=idx++;
}
int d[N],fa[N][25];
void dfs(int x,int y)
{
    d[x]=d[y]+1;
    fa[x][0]=y;
    for(int i=1; (1<<i)<=d[x]; i++)
        fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int i=h[x]; ~i; i=ne[i])
        if (e[i]!=y)
            dfs(e[i],x);
    return;
}
int a[N],b[N];
int n;

void ct(int x,int y) {
    for(int i=h[x];~i;i=ne[i]) {
        int to=e[i];
        if(to==y) continue;
        ct(to,x);
        a[x]+=a[to];
    }
}

int main() {
    cin>>n;

    memset(h,-1,sizeof(h));

    for(int i=1;i<=n-1;i++) {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    add(0,1);
    add(1,0);
    dfs(1,0);
    for(int i=1;i<=n;i++) cin>>b[i];

    for(int i=1;i<=n;i++) {
        int x=i;
        a[x]++;
        for(int j=24;j>=0;j--) {
            if(b[i]&(1<<j)) {
                x=fa[x][j];
            }
        }
        x=fa[x][0];
        a[x]--;
        //cout<<x<<" ";
    }
    ct(1,0);
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
}