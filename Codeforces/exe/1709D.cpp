//
// Created by Xiangrui Yu on 2022/10/11.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 200010, M = 24;

int dp[2][N][M];//dp[1][i][j]表示从i开始2^j个数的最大值
int a[N];
int n,m;

void init(int type) {
    for(int i=0;i<M;i++) {
        for(int j=1;j+(1<<i)-1<=n;j++) {
            if(!i) dp[type][j][i]=a[j];
            else dp[type][j][i]=type?max(dp[type][j][i-1],dp[type][j+(1<<i-1)][i-1]):min(dp[type][j][i-1],dp[type][j+(1<<i-1)][i-1]);
        }
    }
}
int query(int l,int r,int type) {
    int k=log(r-l+1)/log(2);
    return type?max(dp[type][l][k],dp[type][r-(1<<k)+1][k]):min(dp[type][l][k],dp[type][r-(1<<k)+1][k]);
}

void solve() {
    int x1,y1,x2,y2,k;
    cin>>x1>>y1>>x2>>y2>>k;
    if(y1>y2) {
        swap(x1,x2);
        swap(y1,y2);
    }
    if(abs(y1-y2)%k!=0) {
        cout<<"NO\n";
        return;
    }
    int z=abs(x1-x2);
    if(z%k!=0) {
        cout<<"NO\n";
        return;
    }
    int mx = query(y1,y2,1)+1;
    if(mx>m) {
        cout<<"NO\n";
        return;
    }
    mx=max(mx,max(x1,x2));
    //cout<<mx<<endl;
    if((mx-x1)%k==0) {
        cout<<"YES\n";
        return;
    }
    int h=mx+(k-(mx-x1)%k);
    if(h<=m) {
        cout<<"YES\n";
        return;
    }
    else cout<<"NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>m>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    init(1);
    int q;
    cin>>q;
    while(q--) {
        solve();
    }
}