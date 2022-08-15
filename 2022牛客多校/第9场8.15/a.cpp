//
// Created by Xiangrui Yu on 2022/8/15.
//

#include "bits/stdc++.h"
using namespace std;

const int N=100010;
int a[N],t[N];
int n,m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>t[i];

    long long res=0,cnt=0;
    int i=0,j=1;
    while (i<=n) {
        if(i>0&&a[t[i]]--==1) cnt--;
        while(j<=n&&cnt!=m) {
            if(a[t[j]]++==0) cnt++;
            j++;
        }
        if(cnt==m) {
            res+=(n-j+2);
            //cout<<i<<' '<<j<<" "<<n-j+2<<endl;
        }
        i++;
    }
    cout<<res;
}