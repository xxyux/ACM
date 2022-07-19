//
// Created by Xiangrui Yu on 2022/7/19.
//

#include "bits/stdc++.h"
using namespace std;

const int N=200005;

set<int> in[N],out[N];
int fa[N],cnt[N];
int n;

int find(int x) {
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}

void merge(int x,int y) {
    //cout<<x<<' '<<y<<endl;
    x=find(x); y=find(y);
    if(x==y) return;
    if(out[x].size()<out[y].size()) swap(x,y);
    vector<pair<int,int>> v;
    for(auto z:out[y]) {
        out[x].insert(z);
        in[z].insert(x);
        if(in[z].count(y)) in[z].erase(y);
        if(in[z].size()==1) v.push_back({x,z});
    }
    fa[y]=x;
    for(auto t:v) merge(t.first,t.second);
}

int solve() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        in[i].clear();out[i].clear();
        fa[i]=i;cnt[i]=0;
    }
    for(int i=1;i<=n;i++) {
        int m;cin>>m;
        while(m--) {
            int x;cin>>x;
            out[x].insert(i);
            in[i].insert(x);
        }
    }
    for(int i=1;i<=n;i++) {
        if(in[i].size()==1) {
            merge(*in[i].begin(),i);
        }
    }
    int res=0;
    for(int i=1;i<=n;i++) {
        res=max(res,++cnt[find(i)]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    for(int i=1;i<=t;i++) {
        cout<<"Case #"<<i<<": "<<solve()<<endl;
    }
}

