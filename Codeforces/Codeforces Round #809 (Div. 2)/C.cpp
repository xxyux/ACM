//
// Created by Xiangrui Yu on 2022/7/19.
//

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=100010,INF=0x3f3f3f3f3f3f3f3f;
int a[N];
int h[N],t[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    if(n%2==1) {
        int res=0;
        for(int i=2;i<=n-1;i+=2) {
            int x=max(a[i],max(a[i-1]+1,a[i+1]+1))-a[i];
            res+=x;
        }
        cout<<res<<endl;
    }
    else {
        t[n]=t[n+1]=0;
        h[0]=h[1]=0;
        int res=INF;
        for(int i=2;i<=n-1;i++) {
            int x=max(a[i],max(a[i-1]+1,a[i+1]+1))-a[i];
            h[i]=h[i-2]+x;
        }

        for(int i=n-1;i>=2;i--) {
            int x=max(a[i],max(a[i-1]+1,a[i+1]+1))-a[i];
            t[i]=t[i+2]+x;
            //cout<<i<<" "<<t[i]<<endl;
        }

        res=min(res,t[3]);
        for(int i=3;i+2<=n-1;i++) {
            int cnt=0;
            int l=i-1,r=i+2;
            if(l%2==0) cnt+=l/2;
            else cnt+=(l-1)/2;
            if((n-r)%2==0) cnt+=(n-r)/2;
            else cnt+=(n-r+1)/2;
            if(cnt!=n/2-1) continue;
            res=min(res,h[l]+t[r]);
            //cout<<l<<" "<<r<<" "<<h[l]+t[r]<<endl;
        }
        res=min(res,h[n-2]);

        cout<<res<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
}
