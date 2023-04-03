//
// Created by Xiangrui Yu on 2023/4/3.
//

#include "bits/stdc++.h"
using namespace std;
#define int long long

const int N = 5005;
const int inf = 0x3f3f3f3f3f3f3f3f;
int a[N],w[N],c[N];
int dp[N],ndp[N];

void solve() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=k;i++) cin>>c[i];
    for(int i=1;i<=k;i++) cin>>w[i];

    if(n==1) {
        cout<<c[a[1]]<<endl;
        return;
    }
    dp[0]=0;
    for(int i=1;i<=k;i++) dp[i]=inf;

    for(int i=1;i<=n;i++) {
        for(int j=0;j<=k;j++) ndp[j]=inf;

        if(a[i-1]==a[i]) {
            for(int j=0;j<=k;j++) ndp[j]=min(ndp[j],dp[j]+w[a[i]]);
        }
        else {
            for(int j=0;j<=k;j++) {
                if(j==a[i]) {
                    ndp[a[i-1]]=min(ndp[a[i-1]],dp[j]+w[a[i]]);
                }
                ndp[a[i-1]]=min(ndp[a[i-1]],dp[j]+c[a[i]]);
                ndp[j]=min(ndp[j],dp[j]+c[a[i]]);
            }
        }

        for(int j=0;j<=k;j++) dp[j]=ndp[j];
//        for(int j=0;j<=k;j++) cout<<dp[j]<<' ';cout<<endl;
    }
    int ans=inf;
    for(int i=0;i<=k;i++) ans=min(ans,dp[i]);
    cout<<ans<<endl;
}

signed main() {
    int tt;
    cin>>tt;
    while (tt--) solve();
}