//
// Created by Xiangrui Yu on 2022/8/17.
//

#include "bits/stdc++.h"
using namespace std;

const int N=100010;

vector<int> v[N];
int n,q;

int n2=0,n5=0;
int get2(int x) {
    int res=0;
    while (x%2==0) {
        res++;
        x/=2;
    }
    return res;
}
int get5(int x) {
    int res=0;
    while (x%5==0) {
        res++;
        x/=5;
    }
    return res;
}
int son[N];
void dfs1(int x,int y) {
    if(v[x].size()==1&&v[x][0]==y) {
        son[x]=0;
        return;
    }
    for(auto p:v[x]) {
        if(p==y) continue;
        dfs1(p,x);
        son[x]+=son[p]+1;
    }
}
int res[N];
void dfs2(int x,int y) {
    int tn2=n2,tn5=n5;
    int num2=get2(x),num5=get5(x);
    tn2+=num2*(son[x]+1);
    tn5+=num5*(son[x]+1);
    res[x]=min(tn2,tn5);
    //cout<<x<<" "<<n2<<" "<<n5<<" "<<tn2<<" "<<tn5<<endl;
    for(auto p:v[x]) {
        if(p==y) continue;
        int cnt=son[x]-son[p];
        n2+=num2*cnt;
        n5+=num5*cnt;
        dfs2(p,x);
        n2-=num2*cnt;
        n5-=num5*cnt;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n-1;i++) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs1(1,0);
    //for(int i=1;i<=n;i++) cout<<i<<" "<<son[i]<<endl;
    dfs2(1,0);
    while (q--) {
        int x;cin>>x;
        cout<<res[x]<<endl;
    }
}