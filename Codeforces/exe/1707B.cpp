//
// Created by Xiangrui Yu on 2022/10/12.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 100010;
int a[N],n;

void solve() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int p=1;
    for(int k=1;k<=n-1&&p<n;k++) {
        for(int j=n;j>=p;j--) a[j]=a[j]-a[j-1];
        if(p==k) a[p]=0;
        sort(a+p,a+n+1);
        while (a[p]==0&&p<n) {
            p++;
        }
//        for(int i=1;i<=n;i++) cout<<a[i]<<" ";
//        cout<<endl;
    }
    cout<<a[n]<<endl;
}

int main() {
    int t;
    cin>>t;
    while (t--) solve();
}