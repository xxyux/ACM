//
// Created by Xiangrui Yu on 2022/10/15.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 100010;
long long a[N];

void solve() {
    int n,m;
    cin>>n>>m;
    map<long long,int> mp;
    for(int i=1;i<=n;i++) {
        long long s=0;
        for(int j=1;j<=m;j++) {
            long long x;
            cin>>x;
            s+=x*j;
        }
        a[i]=s;
        mp[s]++;
    }
    long long cnt=0;
    for(int i=1;i<=n;i++) {
        if(mp[a[i]]>1) cnt=a[i];
    }
    for(int i=1;i<=n;i++) {
//        cout<<a[i]<<endl;
        if(mp[a[i]]==1) {
            cout<<i<<" "<<a[i]-cnt<<endl;
            return;
        }
    }
}

int main() {
    int t;
    cin>>t;
    while (t--) solve();
}