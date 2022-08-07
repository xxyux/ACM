//
// Created by Xiangrui Yu on 2022/8/7.
//

#include "bits/stdc++.h"
using namespace std;

const int N=200010,M=1000010;
pair<int,int> a[N];
int n;
int res[N];
int d(int x) {
    int y=1;
    for(;y<=x;y<<=1);
    return y>>1;
}


int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        a[i]={d(x),i};
    }
    sort(a+1,a+1+n);

    int m=a[n].first;
    int x=1;
    for(int i=1;i<=m;i++) {
        if(res[i]>0) continue;
        for(int j=i;j<=m;j+=a[x].first) res[j]=a[x].second;
        if(x==n) break;
        x++;
    }
    cout<<m<<endl;
    for(int i=1;i<=m;i++) {
        if(res[i]==0) res[i]=1;
        cout<<res[i]<<" ";
    }
}