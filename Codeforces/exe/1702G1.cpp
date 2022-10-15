//
// Created by Xiangrui Yu on 2022/10/15.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 200010;
vector<int> v[N];
int s[N];
int n;
int st[N];
int f[N];

int ff,m;
void dfs(int x) {
    f[x]=1;
    s[x]=st[x];
    int cnt=0;
    for(auto p:v[x]) {
        if(f[p]==0) {
            dfs(p);
            s[x] += s[p];
            if(s[p]>0) cnt++;
        }
    }
    if(cnt>=2&&m-s[x]>0) ff=0;
    if(cnt>=3) ff=0;
}

int main() {
    cin>>n;
    for(int i=1;i<=n-1;i++) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int q;
    cin>>q;
    while (q--) {
        for(int i=1;i<=n;i++) st[i]=0;
        for(int i=1;i<=n;i++) f[i]=0;
        ff=1;
        cin>>m;
        for(int i=1;i<=m;i++) {
            int x;
            cin>>x;
            st[x]=1;
        }
        dfs(1);
        if(ff) cout<<"YES\n";
        else cout<<"NO\n";
    }
}