//
// Created by Xiangrui Yu on 2022/7/28.
//

#include "bits/stdc++.h"
using namespace std;

#define int long long
#define double long double

const double eps=1e-9;
const int N=100010;
int a[N],n;

double check(double x) {
    double sum=0;
    for(int i=1;i<=n;++i){
        sum+=a[i]-i*x;
    }
    sum/=n;

    double tot=0;
    for(int i=1;i<=n;++i){
        double y=a[i]-i*x;
        tot+=(y-sum)*(y-sum);
    }
    return tot;

}

void solve() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    double l=-1e9,r=1e9,ans=1e50;
    while (r-l>eps) {
        double tl=(l+l+r)/3;
        double tr=(l+r+r)/3;

        double cl=check(tl),cr=check(tr);

        ans=min(ans,min(cl,cr));

        if(cl<cr) {
            r=tr;
        }
        else {
            l=tl;
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(10);

    int t;
    cin>>t;
    while(t--) solve();
}