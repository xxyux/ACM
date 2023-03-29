//
// Created by Xiangrui Yu on 2023/3/27.
//
//最大乘积
#include "bits/stdc++.h"
using namespace std;

const int N = 16;

int a[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    int res=-0x3f3f3f3f;
    for(int i=0;i<(1<<n);i++) {
        int num=0;
        int j=i;
        while (j) {
            if(j%2==1) num++;
            j/=2;
        }
        if(num==m) {
            int mul=1;
            for(j=0;j<n;j++) {
                if(i&(1<<j)) mul*=a[j];
            }
            res=max(res,mul);
        }
    }
    cout<<res<<endl;
}

int main() {
    int tt;
    cin>>tt;
    while (tt--) solve();
}
/*
 1
 5 5
 1 2 3 4 2
 */