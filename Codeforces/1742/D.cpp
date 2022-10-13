//
// Created by Xiangrui Yu on 2022/10/13.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 1010,M = 200010;
int f[N][N];
int a[M],pos[N];

inline int gcd(int a,int b) {
    return b>0 ? gcd(b,a%b):a;
}
void pre() {
    for(int i=1;i<=1000;i++) {
        for(int j=i;j<=1000;j++) {
            f[i][j]=gcd(i,j);
        }
    }
}


void solve() {
    memset(pos,0,sizeof(pos));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        pos[a[i]]=i;
    }
    int res=-1;
    for(int i=1;i<=1000;i++) {
        for(int j=i;j<=1000;j++) {
            if(pos[i]>0&&pos[j]>0) {
                if(f[i][j]==1) {
                    res=max(res,pos[i]+pos[j]);
                }
            }
        }
    }
    cout<<res<<endl;
}

int main() {
    pre();
    int t;
    cin>>t;
    while(t--) solve();
}