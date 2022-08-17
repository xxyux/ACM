//
// Created by Xiangrui Yu on 2022/8/17.
//

#include "bits/stdc++.h"
using namespace std;

const int N=1010;
int a[N][N],n,p;

int main(){
    cin>>n>>p;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];

        for(int i=1;i<=n;i++) {
            if(i<=n%p) cout<<a[i][i]<<" ";
            else cout<<0<<" ";
        }
}