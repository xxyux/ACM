//
// Created by Xiangrui Yu on 2022/8/16.
//

#include "bits/stdc++.h"
using namespace std;

const int N=8010,P=998244353;
typedef long long LL;
LL f[N][N];
int a[N],n;
LL inv[N];
LL ksm(LL x,LL y) {
    LL res=1;
    while(y) {
        if(y&1) res = (res*x)%P;
        y>>=1;
        x=(x*x)%P;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n-1;i++) cin>>a[i];
    for(int i=0;i<N;i++) {
        inv[i]=ksm(i,P-2);
    }
    //for(int i=1;i<=5;i++) cout<<i<<' '<<inv[i]<<endl;

    f[0][1]=1;
    for(int j=0;j<=n;j++) {
        if(j) for(int i=1;i<=n;i++) f[j][i] = (f[j][i] + f[j][i-1])%P;
        for(int i=1;i<=n;i++) {
            f[j+1][i+1] = (f[j+1][i+1] + f[j][i]*inv[a[i]]%P)%P;
            //cout<<f[j+1][i+1]<<" "<<j+1<<" "<<i+1<<endl;
            f[j+1][i+a[i]+1] = (f[j+1][i+a[i]+1] + P - f[j][i]*inv[a[i]]%P)%P;
        }
    }

    LL sum=0,res=0;
    for(int j=1;j<=n;j++) {
        sum = (sum + f[j][n]) % P;
        res = (res + f[j][n] * f[j][n]%P) % P;
    }
    sum=(sum*sum)%P;
    cout<<res*ksm(sum,P-2)%P;
}