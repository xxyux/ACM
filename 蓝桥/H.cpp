//
// Created by Xiangrui Yu on 2023/3/29.
//
//扫地机器人 二分
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int N = 100010;
int a[N];
int n,k;

bool check(int x) {
    int pos=0;
    for(int i=1;i<=k;i++) {
        if((a[i]-pos-1)*2>x) return 0;
        int y;
        if(pos==a[i]) y=x;
        else y=x-2*(a[i]-pos-1);
        int z=y/2;
        pos=a[i];
        pos+=z;
        if(i<k&&pos>a[i+1]) pos=a[i+1];
    }
    if(pos>=n) return 1;
    else return 0;
}

signed main() {
    cin>>n>>k;
    for(int i=1;i<=k;i++) {
        cin>>a[i];
    }
    sort(a+1,a+1+k);
//    for(int i=1;i<=k;i++) cout<<a[i]<<' ';
//    cout<<check(10)<<endl;
    int l=1,r=N*2;
    while (l<r) {
        int mid=(l+r)/2;
        if(check(mid)) {
            r=mid;
        }
        else l=mid+1;
    }
    cout<<l;
}
/*
 10 3
 5
 2
 10
 */