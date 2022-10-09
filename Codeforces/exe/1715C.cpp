//
// Created by Xiangrui Yu on 2022/10/9.
//

#include "bits/stdc++.h"
using namespace std;

#define int long long
const int N = 100010;
int a[N],n,q;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    int res=n*(n+1)/2;
    for(int i=1;i<n;i++) {
        if(a[i]!=a[i+1]) res+=i*(n-i);
    }
    //cout<<res;
    while(q--) {
        int x,y;
        cin>>x>>y;
        if(x+1<=n&&a[x]!=a[x+1]&&y==a[x+1]) {
            res-=x*(n-x);
        }
        if(x+1<=n&&a[x]==a[x+1]&&y!=a[x+1]) {
            res+=x*(n-x);
        }
        if(x-1>=1&&a[x]!=a[x-1]&&y==a[x-1]) {
            res-=(x-1)*(n-x+1);
        }
        if(x-1>=1&&a[x]==a[x-1]&&y!=a[x-1]) {
            res+=(x-1)*(n-x+1);
        }
        a[x]=y;
        cout<<res<<"\n";
    }
}