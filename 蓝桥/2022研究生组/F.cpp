//
// Created by Xiangrui Yu on 2023/4/4.
//

#include "bits/stdc++.h"
using namespace std;

#define int long long
const int mod = 998244353;

int ksm(int a,int b){
    int res=1;
    int cur=a;
    while (b) {
        if(b%2) {
            res*=cur;
            res%=mod;
        }
        cur*=cur;
        cur%=mod;
        b/=2;
    }
    return res%mod;
}
int inv(int x) {
    return ksm(x,mod-2);
}

signed main() {
//    for(int i=1;i<=10;i++) cout<<ksm(2,i)<<" ";
    int n;
    cin>>n;
    int cur=0;
    for(int i=1;i<=n;i++) {
        int a,b;
        cin>>a>>b;
        cur=(cur+1)*b%mod*inv(b-a)%mod;
    }
    cout<<cur;
}