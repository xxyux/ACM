//
// Created by Xiangrui Yu on 2022/10/7.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 300010;
int a[N],n;
int f[N];

void solve() {
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        f[i]=1;
    }

    for(int i=1;i<=n-1;i++) {
        for(int j=max(i-256,0);j<i;j++) {
            if((a[j]^i)<(a[i]^j)) {
                f[i]=max(f[i],f[j]+1);
            }
        }
    }
    int res=0;
    for(int i=0;i<n;i++) res=max(res,f[i]);
    cout<<res<<endl;
}

int main() {
    int tt;
    cin>>tt;
    while(tt--) solve();
}