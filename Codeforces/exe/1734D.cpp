//
// Created by Xiangrui Yu on 2022/10/4.
//
#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N=200010;
int a[N];

void solve() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[n+1]=0;
    int cur=a[k];
    vector<pair<int,int>> vl,vr;
    for(int i=k+1;i<=n;i++) {
        int s=0;
        int m=0;
        int j=i;
        while(j<=n&&s+a[j]<0) {
            s+=a[j];
            m=min(m,s);
            j++;
        }
        s+=a[j];
        m=min(m,s);
        vr.push_back({s,m});
        i=j;
    }
    for(int i=k-1;i>=1;i--) {
        int s=0;
        int m=0;
        int j=i;
        while(j>=1&&s+a[j]<0) {
            s+=a[j];
            m=min(m,s);
            j--;
        }
        s+=a[j];
        m=min(m,s);
        vl.push_back({s,m});
        i=j;
    }
    int l=0,r=0;
    while(l<vl.size()&&r<vr.size()) {
        int f1=0,f2=0;
        if(cur+vr[r].second>=0) {
            cur+=vr[r].first;
            r++;
            f1=1;
        }
        if(cur+vl[l].second>=0) {
            cur+=vl[l].first;
            l++;
            f2=1;
        }
        if(f1==0&&f2==0) {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--) solve();
}

