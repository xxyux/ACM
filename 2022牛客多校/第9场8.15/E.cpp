//
// Created by Xiangrui Yu on 2022/8/16.
//

#include "bits/stdc++.h"
using namespace std;

int a[32];
void solve() {
    int n;
    cin>>n;
    vector<int> v[32];
    int m=0;
    for(int i=0;i<=30;i++) {
        if(n&(1<<i)) m=i;
    }
    for(int i=1;i<=m;i++) {
        v[i].push_back(2*i);
        v[i].push_back(2*i-1);
    }
    memset(a,0,sizeof(a));
    int cnt=0;
    for(int i=m-1;i>=0;i--) {
        if(n&(1<<i)) {
            int x=m-i;
            a[i]=x-cnt;
            cnt=x;
        }
    }
    int idx=2*m+1;
    for(int i=0;i<=m-1;i++) {
        while (a[i]--) {
            v[i].push_back(idx++);
        }
    }
    v[m].push_back(idx);
    cout<<idx<<endl;
    for(int i=0;i<=m;i++) {
        for(auto p:v[i]) cout<<p<<" ";
    }
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
}