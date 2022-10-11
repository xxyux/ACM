//
// Created by Xiangrui Yu on 2022/10/11.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 200010;
vector<int> v[N];
int fa[N];
int n,k;
pair<int,int> h[N];
void dfs(int x) {
    for(auto p:v[x]) {
        h[p]={h[x].first+1,p};
        dfs(p);
    }
}
int in[N];
void down(int x) {
    if(in[x]==1) return;
    in[x]=1;
    for(auto p:v[x]) down(p);
}
int res;
void up(int x,int cnt) {
    if(fa[x]==1||cnt==1) {
        res=x;
        return;
    }
    up(fa[x],cnt-1);
}
bool check(int x) {
    for(int i=1;i<=n;i++) in[i]=0;
    int cnt=0;
    for(int i=n;i>=2;i--) {
        int pos=h[i].second,ht=h[i].first;
        if(in[pos]==1||ht<=x) continue;
        up(pos,x);
        down(res);
        cnt++;
    }
    //cout<<x<<" "<<cnt<<endl;
    return cnt <= k;
}

void solve() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) v[i].clear();
    h[1]={0,1};
    for(int i=2;i<=n;i++) {
        int x;
        cin>>x;
        v[x].push_back(i);
        fa[i]=x;
    }
    dfs(1);
    sort(h+1,h+1+n);
    int l=1,r=h[n].first;
    while (l<r) {
        int mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while (t--) solve();
}