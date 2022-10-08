//
// Created by Xiangrui Yu on 2022/10/8.
//
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include "bits/stdc++.h"
using namespace std;

const int N = 100010,M = 200010;
int a[N][30];
vector<pair<int,int>> v[N][30];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        for(int j=0;j<30;j++) {
            int c=(z>>j)&1;
            v[x][j].emplace_back(y,c);
            v[y][j].emplace_back(x,c);
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<30;j++) a[i][j]=1;

    for(int i=1;i<=n;i++) {
        for(int j=0;j<30;j++) {
            for(auto [y,z]:v[i][j]) {
                if(z==0) {
                    a[i][j]=0;
                    a[y][j]=0;
                }
            }
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<30;j++) {
            int cnt=0,s=0;
            int f=1;
            for(auto [y,z]:v[i][j]) {
                if(z==1) {
                    if(y!=i) s++;
                    else f=0;
                    if(y!=i&&a[y][j]==1) cnt++;
                }
            }
            if(cnt==s&&f) a[i][j]=0;
        }
    }

    for(int i=1;i<=n;i++) {
        long long sum=0;
        for(int j=0;j<30;j++) {
            if(a[i][j]==1) sum+=(1<<j);
        }
        cout<<sum<<" ";
    }
}