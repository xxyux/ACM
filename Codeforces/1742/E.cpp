//
// Created by Xiangrui Yu on 2022/10/13.
//

#include "bits/stdc++.h"
using namespace std;

#define int long long
const int N = 200010;
int a[N],b[N],s[N];
int n,q;


void solve() {
    cin>>n>>q;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        b[i]=max(b[i-1],a[i]);
        s[i]=s[i-1]+a[i];
    }

    while (q--) {
        int x;
        cin>>x;
        int l=0,r=n;
        while (l<r) {
//            cout<<l<<" "<<r<<endl;
            if(l==0&&r==1) {
                if(b[1]<=x) l=1;
                break;
            }
            if(l==r-1) {
                if(b[l]<=x&&b[r]<=x) l=r;
                break;
            }
            int mid=(l+r)/2;
            if(b[mid]<=x) l=mid;
            else r=mid-1;
        }
        cout<<s[l]<<" ";
    }
    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--) solve();
}