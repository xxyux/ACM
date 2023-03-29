//
// Created by Xiangrui Yu on 2023/3/28.
//
//dp
#include "bits/stdc++.h"
using namespace std;

const int N = 1010;
int a[N],b[N];
int n,m;
int dp[N][N];

int main() {
    string s,t;
    cin>>s>>t;
    map<string,int> mp;
    int idx=1;
    string cur;
    for(int i=0;i<s.length();i++) {
        char p=s[i];
        if(isupper(p)) {
            if(cur!="") {
                if(mp[cur]==0) mp[cur]=idx++;
                a[++n]=mp[cur];
            }
            cur=p;
        }
        else {
            cur+=p;
        }
    }
    if(cur!="") {
        if(mp[cur]==0) mp[cur]=idx++;
        a[++n]=mp[cur];
    }
    cur="";
    for(int i=0;i<t.length();i++) {
        char p=t[i];
        if(isupper(p)) {
            if(cur!="") {
                if(mp[cur]==0) mp[cur]=idx++;
                b[++m]=mp[cur];
            }
            cur=p;
        }
        else {
            cur+=p;
        }
    }
    if(cur!="") {
        if(mp[cur]==0) mp[cur]=idx++;
        b[++m]=mp[cur];
    }
//    for(int i=1;i<=n;i++) cout<<a[i]<<' ';cout<<endl;
//    for(int i=1;i<=m;i++) cout<<b[i]<<' ';cout<<endl;
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            dp[i][j]=dp[i-1][j];//不取b[i]
            dp[i][j]=max(dp[i][j],dp[i][j-1]);//取b[i]
            if(a[j]==b[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);//取b[i]

//            cout<<dp[i][j]<<" ";
        }
//        cout<<endl;
    }
    cout<<dp[m][n];
}
/*
LanQiaoBei
LanTaiXianQiao
 */
