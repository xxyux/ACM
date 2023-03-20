//
// Created by Xiangrui Yu on 2023/3/19.
//
#include "bits/stdc++.h"
using namespace std;

const int N = 200010;

int a[N];
int s[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];

    int l=1,r=n;
    while (l!=r) {
        int mid=(l+r)/2;
        cout<<"? "<<mid-l+1;
        for(int i=l;i<=mid;i++) cout<<" "<<i;
        cout<<endl;
        int res;
        cin>>res;
        if(res==s[mid]-s[l-1]) l=mid+1;
        else r=mid;
    }
    cout<<"! "<<l<<endl;
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
