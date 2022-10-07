//
// Created by Xiangrui Yu on 2022/10/7.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 5010,M = (1<<13);
const int inf = 1e9;
int f[N][M];//5000*8192 4e7
int a[N],n;

void solve() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        for(int j=0;j<M;j++) f[i][j]=inf;
    }

    for(int i=1;i<=n;i++) {
        for(int j=0;j<M;j++) {
            //1位
            f[i][a[i]^j]=min(f[i][a[i]^j],f[i-1][0]+(j!=0));
            if(i>=2) {//2位
                f[i][a[i]^j]=min(f[i][a[i]^j],f[i-1][j]+1);
            }
        }
    }
//    for(int i=1;i<=n;i++) {
//        for(int j=0;j<=a[i];j++) cout<<f[i][j]<<" ";
//        cout<<endl;
//    }
    cout<<f[n][0]<<endl;
}

int main() {
    int tt;
    cin>>tt;
    while(tt--) solve();
}