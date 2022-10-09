//
// Created by Xiangrui Yu on 2022/10/9.
//

#include "bits/stdc++.h"
using namespace std;

#define int long long
struct node {
    int x,y;
    bool operator < (node t) const{
        if(x!=t.x) return x<t.x;
        return y>t.y;
    }
};
set<node> s;
int n;
const int N = 200010;
struct edge {
    int to,a,b;
};
vector<edge> v[N];
int ans[N];

void dfs(int x,int sum1,int sum2,int d) {
    if(x!=1) {
       if(s.upper_bound({sum1,0})==s.end()) {//集合里没有比sum1大的数
           if(s.empty()) ans[x]=0;
           else {
               auto p=s.end();
               p--;
               ans[x]=p->y;
           }
       }
       else {
           auto p=s.upper_bound({sum1,0});
           if (p == s.begin()) ans[x] = 0;
           else {
               p--;
               ans[x] = p->y;
           }
       }
    }
    for(auto [y,a,b]:v[x]) {
        s.insert({sum2+b,d});
        dfs(y,sum1+a,sum2+b,d+1);
        s.erase({sum2+b,d});
    }
}

void solve() {
    cin>>n;
    s.clear();
    for(int i=1;i<=n;i++) v[i].clear();
    for(int i=2;i<=n;i++) {
        int x,a,b;
        cin>>x>>a>>b;
        v[x].push_back({i,a,b});
    }
    dfs(1,0,0,1);
    for(int i=2;i<=n;i++) cout<<ans[i]<<' ';cout<<endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--) solve();
}
