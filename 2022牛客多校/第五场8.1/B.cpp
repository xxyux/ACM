//
// Created by Xiangrui Yu on 2022/8/2.
//

#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=100010;
int a[N],n,m;
//a[i]/k +i
int b[N];
int k;
bool cmp(int x,int y) {
    return a[x]+x*k<a[y]+y*k;
}

bool check() {
    for(int i=1;i<=n;i++) b[i]=i;
    sort(b+1,b+1+n,cmp);

    int sum=0;
    for(int i=1;i<=k;i++) {
        sum+=a[b[i]]+k*b[i];
    }
    if(sum<=m) return true;
    return false;
}
signed main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }

    int l=0,r=n;
    int ans=0;
    while(l<r) {
        int mid=(l+r)/2;
        k=mid;
        if(check()) {
            ans=mid;
            l=mid+1;
        }
        else r=mid;
    }
    cout<<ans;
}