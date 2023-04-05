//
// Created by Xiangrui Yu on 2023/4/4.
//

#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 100010;
int l[N],r[N],a[N];
int n,m,x;
int p[1024*1024+5];
int last[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[a[i]]=i;
        last[i]=max(last[i-1],p[a[i]^x]);
    }
    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i];
        if(l[i]<=last[r[i]]) cout<<"yes\n";
        else cout<<"no\n";
    }

}