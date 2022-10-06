//
// Created by Xiangrui Yu on 2022/10/5.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 100010;
int a[N],n;
int b[N];

int main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    int cnt=0;
    for(int i=1;i<=n;i++) {
        if(a[i]%3==0) {
            b[i]=1;
            cnt++;
        }
    }
    if(cnt>n/2) {
        cout<<2<<endl;
        int cnt1=cnt-n/2;
        for(int i=1;i<=n;i++) {
            if(b[i]==1&&cnt1) {
                b[i]=0;
                cnt1--;
            }
        }
        for(int i=1;i<=n;i++) cout<<b[i];
    }
    else {
        cout<<0<<endl;
        int cnt1=n/2-cnt;
        for(int i=1;i<=n;i++) {
            if(b[i]==0&&cnt1) {
                b[i]=1;
                cnt1--;
            }
        }
        for(int i=1;i<=n;i++) cout<<b[i];
    }
}