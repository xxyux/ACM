//
// Created by Xiangrui Yu on 2023/3/20.
//


#include "bits/stdc++.h"
using namespace std;

const int N = 200010;

int a[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    long long max=0;
    int ff=1;
    for(int i=1;i<=n;i++) {
        if(a[i]==1) max++;
        else {
            if(a[i]>max) {
                ff=0;
                break;
            }
            else max+=a[i];
        }
    }
    if(ff) cout<<"YES\n";
    else cout<<"NO\n";
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