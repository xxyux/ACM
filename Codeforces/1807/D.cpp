//
// Created by Xiangrui Yu on 2023/3/19.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 200010;

int a[N];
int s[N];

void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        a[i]%=2;
    }
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    while(q--) {
        int l,r,k;
        cin>>l>>r>>k;
        k%=2;
        int res=s[l-1]+s[n]-s[r]+(r-l+1)*k;
        if (res%2==1) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt=1;
    cin>>tt;
    while (tt--) {
        solve();
    }
}