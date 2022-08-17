//
// Created by Xiangrui Yu on 2022/8/17.
//

#include "bits/stdc++.h"
using namespace std;

const int N=1000010;
int a[N],n;
void solve() {
    cin>>n;
    int n1=0,n2=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) {
        int x;
        if(i==1) x=(a[i]-a[n]+3)%3;
        else x=(a[i]-a[i-1]+3)%3;
        if(x==1) n1++;
        if(x==2) n2++;
    }
    if(n1>=n2) cout<<"Yes\n";
    else cout<<"No\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--) solve();
}