//
// Created by Xiangrui Yu on 2023/4/12.
//

#include "bits/stdc++.h"
using namespace std;

#define int long long
const int M = 55;
int a[M];
map<int,set<int>> mp;

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    mp.clear();
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            int x=a[j]-a[i];
            for(int d=1;d*d<=x;d++) {
                if(x%d==0) {
                    if(((a[j]-a[i])/d-d)%2==0&&((a[j]-a[i])/d+d)%2==0){
                        int p=((a[j]-a[i])/d-d)/2;
                        int q=((a[j]-a[i])/d+d)/2;
                        if(p*p-a[i]>=0) {
                            mp[p * p - a[i]].insert(i);
                            mp[p * p - a[i]].insert(j);
                        }
                    }
                }
            }
        }
    }
    int res=1;
    for(auto [u,v]:mp) {
//        cout<<u<<" "<<v.size()<<endl;
        res=max(res,(int)v.size());
    }
    cout<<res<<endl;
}

signed main() {
    int tt;
    cin>>tt;
    while (tt--) solve();
}
