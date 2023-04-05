//
// Created by Xiangrui Yu on 2023/4/4.
//


#include "bits/stdc++.h"
using namespace std;

#define int long long
signed main() {
    int n;
    cin>>n;
    int res=0;
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) {
            res++;
            while (n%i==0) n/=i;
        }
    }
    if(n) res++;
    cout<<res;
}