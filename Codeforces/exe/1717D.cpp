//
// Created by Xiangrui Yu on 2022/10/8.
//

#include "bits/stdc++.h"
using namespace std;

const int P = 1e9+7;
const int N = 100010;
//求 m^k mod p，时间复杂度 O(logk)。

long long qmi(long long m, int k, int p)
{
    long long res = 1 % p, t = m;
    while (k)
    {
        if (k&1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}
//1+C(n,0)+C(0,1)+...+C(n,k)
//C(n,i) = fac(n) * inv(i) * inv(n-i)
long long fac[N],inv[N];
int main() {
    int n,k;
    cin>>n>>k;
    fac[0]=1;
    for(int i=1;i<=n;i++) {
        fac[i]=fac[i-1]*i;
        fac[i]%=P;
    }
    inv[n]=qmi(fac[n],P-2,P);
    for(int i=n-1;i>=0;i--) {
        inv[i]=inv[i+1]*(i+1);
        inv[i]%=P;
    }
    long long sum=0;
    for(int i=min(n,k);i>=0;i--) {
        sum+=((fac[n]*inv[i])%P*inv[n-i])%P;
        sum%=P;
    }
    cout<<sum;
}