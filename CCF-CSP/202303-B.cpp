//
// Created by Xiangrui Yu on 2023/3/30.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 100010;
int a[N],b[N];
int n,m,k;

int check(int x) {
    int res=0;
    for(int i=1;i<=n;i++) {
        if(x>=a[i]) continue;
        res+=(a[i]-x)*b[i];
    }
    if(res<=m) return 1;
    else return 0;
}

int main() {
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];

    int l=k,r=N;
    while (l<r) {
        int mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l;
}