//
// Created by Xiangrui Yu on 2023/3/19.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 100010;


void solve() {
    int n;
    cin>>n;
    int s1=0,s2=0;
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        if(x%2==0) s1+=x;
        else s2+=x;
    }
    if(s1>s2) cout<<"YES\n";
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