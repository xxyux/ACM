//
// Created by Xiangrui Yu on 2023/3/28.
//
//质数行者

#include "bits/stdc++.h"
using namespace std;

#define int long long

bool prime(int x) {
    if(x<2) return 0;
    for(int i=2;i*i<=x;i++) {
        if(x%i==0) return 0;
    }
    return 1;
}

const int N = 1010;
const int mod = 1e9+7;

int dp[N][N];//dp[i][j] 当前的数是i，长度为j的方案数
int inv[N*3],fac[N*3];

int qpow(int a,int b) {
    int ans=1,base=a;
    while (b) {
        if(b&1) ans=ans*base%mod;
        base=base*base%mod;
        b>>=1;
    }
    return ans%mod;
}

void init() {
    fac[0]=1;
    inv[0]=1;
    for(int i=1;i<N*3;i++) {
        fac[i]=fac[i-1]*i%mod;
        inv[i]=qpow(fac[i],mod-2);
    }
}

int tmp[N*2];
int get(int a,int b,int c) {
    memset(tmp,0,sizeof tmp);
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            tmp[i+j]+=dp[a][i]*dp[b][j]%mod*inv[i]%mod*inv[j]%mod;
            tmp[i+j]%=mod;
        }
    }
//    for(int i=1;i<=5;i++) cout<<tmp[i]<<' ';cout<<endl;
    int res=0;
    for(int i=0;i<2*N;i++) {
        for(int j=0;j<N;j++) {
            res+=tmp[i]*fac[i+j]%mod*dp[c][j]%mod*inv[j]%mod;
            res%=mod;
        }
    }
    return res;
}

signed main() {
    init();
    vector<int> pr;
    for(int i=0;i<N;i++) {
        if(prime(i)) pr.push_back(i);
    }
    dp[1][0]=1;
    for(int i=1;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(!dp[i][j]) continue;
            for (int k = 0; k < pr.size(); k++) {
                int p = pr[k];
                if(i+p<N&&j+1<N) dp[i+p][j+1]=(dp[i+p][j+1]+dp[i][j])%mod;
            }
        }
    }

    int n,m,w;
    cin>>n>>m>>w;
    int r1,c1,h1,r2,c2,h2;
    cin>>r1>>c1>>h1>>r2>>c2>>h2;

//    cout<<get(5,5,1)<<endl;
    int res=get(n,m,w);

    res-=get(r1,c1,h1)*get(n-r1+1,m-c1+1,w-h1+1)%mod;
    res-=get(r2,c2,h2)*get(n-r2+1,m-c2+1,w-h2+1)%mod;

    if(r1<=r2&&c1<=c2&&h1<=h2) {
        res+=get(r1,c1,h1)*get(r2-r1+1,c2-c1+1,h2-h1+1)%mod*get(n-r2+1,m-c2+1,w-h2+1)%mod;
        res%=mod;
    }
    swap(r1,r2);
    swap(c1,c2);
    swap(h1,h2);
    if(r1<=r2&&c1<=c2&&h1<=h2) {
        res+=get(r1,c1,h1)*get(r2-r1+1,c2-c1+1,h2-h1+1)%mod*get(n-r2+1,m-c2+1,w-h2+1)%mod;
        res%=mod;
    }
    res=(res%mod+mod)%mod;
    cout<<res;
}
/*
5 6 1
3 4 1 1 2 1
 */

