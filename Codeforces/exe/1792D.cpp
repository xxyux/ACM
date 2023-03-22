//
// Created by Xiangrui Yu on 2023/3/22.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 50005;
const int M = 11;

vector<int> v[N];
int p[M];
int cnt=0;
int trie[N*M][M];

int add(int x,int pre) {
    if(trie[pre][x]==0) {
        trie[pre][x]=++cnt;
    }
    return trie[pre][x];
}

void solve() {
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++) {
        v[i].clear();
        memset(p,0,sizeof(p));
        for(int j=1;j<=m;j++) {
            int x;
            cin>>x;
            v[i].push_back(x);
            p[x]=j;
        }
        int cur=0;
        for(int j=1;j<=m;j++) {
            cur=add(p[j],cur);
        }
    }

    for(int i=1;i<=n;i++) {
        int cur=0;
        int res=0;
        while (res<m&&trie[cur][v[i][res]]) {
            cur=trie[cur][v[i][res]];
            if(cur==0) break;
            res++;
        }
        cout<<res<<" ";
    }
    cout<<endl;

    for(int i=0;i<=cnt;i++)
        for(int j=1;j<=m;j++)
            trie[i][j]=0;
    cnt=0;
}

int main() {
    int tt;
    cin>>tt;
    while (tt--) {
        solve();
    }

}