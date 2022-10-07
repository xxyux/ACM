//
// Created by Xiangrui Yu on 2022/10/7.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 100010;
int a[N],n;

void solve() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        a[i]^=a[i-1];
    }
    set<int> s;
    s.insert(0);
    int res=n;
    for(int i=1;i<=n;i++) {
        if(s.count(a[i])) {
            res--;
            s.clear();
        }
        s.insert(a[i]);
    }
    cout<<res<<endl;
}

int main() {
    int tt;
    cin>>tt;
    while(tt--) solve();
}