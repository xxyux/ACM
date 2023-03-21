//
// Created by Xiangrui Yu on 2023/3/21.
//

#include "bits/stdc++.h"
using namespace std;

const int P = 998244353;

bool isprime(int x) {
    if(x<2) return false;
    for(int i=2;i*i<=x;i++) {
        if(x%i==0) return false;
    }
    return true;
}

const int N = 5050;
int b[N],c[N];
map<int,int> p,up;//次数
vector<int> vp,vup;//val

const int M = 1000010;
long long fac[M];
long long inv[M];
long long sv[M];
//n!/( c1!c2!...cn! )

inline long long qpow(long long a, int b) {
    long long ans = 1;
    a = (a % P + P) % P;
    for (; b; b >>= 1) {
        if (b & 1) ans = (a * ans) % P;
        a = (a * a) % P;
    }
    return ans;
}

void f(int n) {
    fac[0] = 1;
    for (int i = 1; i <=n; ++i) fac[i] = fac[i - 1] * i % P;
    sv[n] = qpow(fac[n], P - 2);
// 当然这里也可以用 exgcd 来求逆元,视个人喜好而定.
    for (int i = n; i >= 1; --i) sv[i - 1] = sv[i] * i % P;
    for (int i = 1; i <= n; ++i) inv[i] = sv[i] * fac[i-1] % P;
}

long long dp[N][N];
//dp[i][j] 前i个 选了j个
//dp[i][j]=dp[i][j-1]*(1/(b[j]-1)!)+dp[i-1][j]*(1/b[j]!)
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=2*n;i++) {
        int x;
        cin>>x;
        if(isprime(x)) {
            if(p[x]==0) vp.push_back(x);
            p[x]++;
        }
        else {
            if(up[x]==0) vup.push_back(x);
            up[x]++;
        }
    }
    for(int i=0;i<vp.size();i++) {
        b[i]=p[vp[i]];
    }
    for(int i=0;i<vup.size();i++) {
        c[i]=up[vup[i]];
    }

    f(M-1);

    //n!/(c1!c2!...cn!)
    long long res=fac[n];
    for(int i=0;i<vup.size();i++)
        res=res*sv[c[i]]%P;

    //sum{ 1/b1!b2!...bn! }

    int m=vp.size();
    if(m<n) {
        cout<<0;
        return 0;
    }
//dp[i][j] 前i个 选了j个
//dp[i][j]=dp[i-1][j-1]*(1/(b[i]-1)!)+dp[i-1][j]*(1/b[i]!)

    dp[0][0]=1;
    for(int i=1;i<=m;i++) {
        dp[i][0]=sv[b[i-1]]*dp[i-1][0]%P;
        for(int j=1;j<=min(i,n);j++) {
            dp[i][j] = dp[i - 1][j - 1] * sv[b[i - 1] - 1] % P + dp[i - 1][j] * sv[b[i - 1]] % P;
            dp[i][j] %= P;
//          cout<<i<<' '<<j<<" "<<dp[i][j]<<endl;
        }
    }

    res=res*dp[m][n]%P;
    cout<<res;
}