//
// Created by Xiangrui Yu on 2023/4/3.
//

#include "bits/stdc++.h"
using namespace std;

#define int long long

int gcd(int x,int y) {
    return x==0?y:gcd(y%x,x);
}
const int N = 200010;
int a[N],b[N];

void solve() {
    int n;
    cin>>n;
    int res=0;
    int cur_lcm=1;
    for(int i=1;i<=n;i++) {
        cin>>a[i]>>b[i];
    }
    int sum=1;
    for(int i=1;i<=n;i++) {
        if(i==1) {
            cur_lcm=b[i];
            res++;
            sum=a[i]*b[i];
        }
        else {
            sum=gcd(sum,a[i]*b[i]);
            cur_lcm=cur_lcm*b[i]/gcd(cur_lcm,b[i]);

            if(sum%cur_lcm) {
                cur_lcm=b[i];
                res++;
                sum=a[i]*b[i];
            }
        }
    }
    cout<<res<<endl;
}

signed main() {
    int tt;
    cin>>tt;
    while (tt--) solve();
}