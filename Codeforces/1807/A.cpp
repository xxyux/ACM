//
// Created by Xiangrui Yu on 2023/3/19.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 100010;

void solve() {
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b==c) cout<<"+\n";
    else cout<<"-\n";
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