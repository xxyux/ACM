//
// Created by Xiangrui Yu on 2022/8/7.
//

#include "bits/stdc++.h"
using namespace std;

const int N=505;
char c[N][N];
int f[N][N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) cin>>c[i][j];
    }
    memset(f,0,sizeof(f));
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--) {
            if((i+j)%2) {
                if(i+1<=n&&j+1<=m) f[i][j]=f[i+1][j]&f[i][j+1];
                else if(i+1<=n) f[i][j]=f[i+1][j];
                else if(j+1<=m) f[i][j]=f[i][j+1];
            }
            else {
                if(i+1<=n) f[i][j]|=f[i+1][j];
                if(j+1<=m) f[i][j]|=f[i][j+1];
            }
            if(c[i][j]=='A') f[i][j]=1;
            if(c[i][j]=='B') f[i][j]=0;
        }

    if(f[1][1]) cout<<"yes ";
    else cout<<"no ";

    memset(f,0,sizeof(f));
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--) {
            if(i==n&&j==m) {
                if(c[i][j]!='.') f[i][j]=0;
                else f[i][j]=1;
                continue;
            }
            if(c[i][j]!='.') {
                f[i][j]=0;continue;
            }
            if((i+j)%2) {
                if(i+1<=n&&j+1<=m) f[i][j]=f[i+1][j]&f[i][j+1];
                else if(i+1<=n) f[i][j]=f[i+1][j];
                else if(j+1<=m) f[i][j]=f[i][j+1];
            }
            else {
                if(i+1<=n) f[i][j]|=f[i+1][j];
                if(j+1<=m) f[i][j]|=f[i][j+1];
            }
        }

    if(f[1][1]) cout<<"yes ";
    else cout<<"no ";

    memset(f,0,sizeof(f));
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--) {
            if((i+j)%2) {
                if(i+1<=n&&j+1<=m) f[i][j]=f[i+1][j]&f[i][j+1];
                else if(i+1<=n) f[i][j]=f[i+1][j];
                else if(j+1<=m) f[i][j]=f[i][j+1];
            }
            else {
                if(i+1<=n) f[i][j]|=f[i+1][j];
                if(j+1<=m) f[i][j]|=f[i][j+1];
            }
            if(c[i][j]=='A') f[i][j]=0;
            if(c[i][j]=='B') f[i][j]=1;
        }

    if(f[1][1]) cout<<"yes\n";
    else cout<<"no\n";
}

int main() {
    int t;
    cin>>t;
    while (t--) solve();
}