//
// Created by Xiangrui Yu on 2022/10/13.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 110;
int a[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++) {
        if(a[i]==a[i+1]) {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}