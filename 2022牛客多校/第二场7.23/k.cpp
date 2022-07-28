//
// Created by Xiangrui Yu on 2022/7/28.
//

#include "bits/stdc++.h"
using namespace std;

typedef long long LL;
const int N=205,mod=1e9+7;
string s;
int n,m;
int dp[N][N][N];

void add(int &a,int b) {
    a=(LL)(a+b)%mod;
}

void solve() {

    cin>>n>>m>>s;
    for(int i=0;i<=m;i++) {
        for(int j=0;j<=n;j++) {
            memset(dp[i][j],0,sizeof(dp[i][j]));
        }
    }
    s=" "+s;
    dp[0][0][0]=1;

    for(int i=0;i<m;i++) {
        for(int j=0;j<=i;j++) {
            for(int k=0;k<=i;k++) {
                //if(j>=n) continue;
                if(k>0) {
                    if(s[j+1]==')') {
                        add(dp[i+1][j+1][k-1],dp[i][j][k]);
                        //if(dp[i+1][j+1][k-1]>0) cout<<i+1<<' '<<j+1<<" "<<k-1<<' '<<dp[i+1][j+1][k-1]<<endl;
                    }
                    else  {
                        add(dp[i+1][j][k-1],dp[i][j][k]);
                        //if(dp[i+1][j][k-1]>0) cout<<i+1<<' '<<j<<" "<<k-1<<' '<<dp[i+1][j][k-1]<<endl;
                    }
                }
                {
                    if(s[j+1]=='('){
                        add(dp[i+1][j+1][k+1],dp[i][j][k]);
                        //if(dp[i+1][j+1][k+1]>0) cout<<i+1<<' '<<j+1<<" "<<k+1<<' '<<dp[i+1][j+1][k+1]<<endl;
                    }else{
                        add(dp[i+1][j][k+1],dp[i][j][k]);
                        //if(dp[i+1][j][k+1]>0) cout<<i+1<<' '<<j<<" "<<k+1<<' '<<dp[i+1][j][k+1]<<endl;
                    }
                }
            }
        }
    }
    cout<<dp[m][n][0]<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) solve();
}