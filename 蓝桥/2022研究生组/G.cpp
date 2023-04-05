//
// Created by Xiangrui Yu on 2023/4/4.
//

#include "bits/stdc++.h"
using namespace std;

#define int long long
const int mod = 998244353;


signed main() {
    int n;
    cin>>n;

    int c=1,s=0;

    for(int i=1;i<=n;i++) {
        s=i*s%mod+(i*(i-1)/2)%mod*c;
        s%=mod;
        c=c*i%mod;
    }
    cout<<s;
}