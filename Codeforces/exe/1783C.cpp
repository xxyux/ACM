//
// Created by Xiangrui Yu on 2023/4/10.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 500010;
int a[N],s[N];
int b[N];
int n,m;
int c[N];
int d[N];

bool cmp(int x,int y) {
    return a[x]<a[y];
}

bool check(int rank) {
    int x=n-(rank-1);
    if(s[x]<=m) return true;
    if(s[x-1]<=m&&d[x]<=x-1) return true;
    if(x>=2&&d[x]>x-2&&s[x-2]<=m-a[x]&&m>=a[x]) return true;
    return false;
}

void solve() {
    for(int i=0;i<=1000;i++) c[i]=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        b[i]=i;
    }
    sort(b+1,b+1+n,cmp);
    for(int i=1;i<=n;i++) {
        if(c[a[b[i]]]==0) c[a[b[i]]]=i;
    }
    for(int i=1;i<=n;i++) {
        d[i]=c[a[i]];
    }
//    for(int i=1;i<=n;i++) cout<<d[i]<<" ";cout<<endl;
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[b[i]];

    int l=1,r=n+1;
    while (l<r) {
        int mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin>>tt;
    while (tt--) solve();
}