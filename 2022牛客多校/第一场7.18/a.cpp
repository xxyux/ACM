//
// Created by Xiangrui Yu on 2022/7/19.
//
#include "bits/stdc++.h"
using namespace std;

const int N=200010,INF=0x3f3f3f3f;
typedef pair<int, int> PII;
#define x first
#define y second
PII a[N];
int n;

int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        int xs,rs;
        cin>>xs>>rs;
        a[i]={xs-rs,xs+rs};
    }
    sort(a+1,a+1+n);
    int res=0,mr=-INF;
    for(int i=1;i<=n;i++) {
        if(i!=1&&mr < a[i].x) {
            res+=a[i].x-mr;
        }
        mr=max(mr,a[i].y);
    }
    cout<<res;
}