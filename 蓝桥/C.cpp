//
// Created by Xiangrui Yu on 2023/3/27.
//
//砝码称重
#include "bits/stdc++.h"
using namespace std;

const int N = 100010;
int dp[N];
int a[N];

int main() {
    int n;
    cin>>n;
    dp[0]=1;
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        memset(a,0,sizeof a);
        for(int j=0;j<N;j++) {
            if(dp[j]) {
                if(j+x<N) a[j+x]=1;
                if(j-x>0) a[j-x]=1;
                if(x-j>0) a[x-j]=1;

            }
        }
        for(int j=1;j<N;j++) dp[j]|=a[j];
//        for(int j=1;j<N;j++) {
//            if(dp[j]==1) cout<<j<<" ";
//        }
//        cout<<endl;
    }
    int res=0;
    for(int i=1;i<N;i++) {
        if (dp[i]) {
//            cout<<i<<" ";
            res++;
        }
    }
    cout<<res;
}
/*
3
1 4 6
*/