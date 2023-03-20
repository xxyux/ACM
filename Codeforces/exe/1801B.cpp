//
// Created by Xiangrui Yu on 2023/3/20.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 500010;

int a[N];
int b[N];
int c[N];

bool cmp(int x,int y) {
    return b[x]>b[y];
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        c[i]=i;
        cin>>a[i]>>b[i];
    }
    sort(c+1,c+1+n,cmp);

    int res=0x3f3f3f3f;
    multiset<int> s;
    for(int i=1;i<=n;i++) s.insert(a[i]);
    int pre_max=0;
    for(int i=1;i<=n;i++) {
        int pos=c[i];
        auto p=s.lower_bound(a[pos]);
        s.erase(p);

        p=s.lower_bound(b[pos]);
        int x=-1,y=-1;
        if(p==s.end()) {//lost y
            if(!s.empty()) {
                p--;
                x=*p;
            }
        }
        else {
            y=*p;
            if(p!=s.begin()) {//lost x
                p--;
                x=*p;
            }
        }

        if(i==1) {
            if(x!=-1) res=min(res,abs(b[pos]-x));
            if(y!=-1) res=min(res,abs(b[pos]-y));
        }
        else {
            int tmp=abs(b[pos]-pre_max);
            if(x!=-1) {
                if(pre_max<=x) tmp=min(tmp,abs(b[pos]-x));
            }
            if(y!=-1) {
                if(pre_max<=y) tmp=min(tmp,abs(b[pos]-y));
            }
            res=min(res,tmp);
        }

        pre_max=max(pre_max,a[pos]);
    }
    cout<<res<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     int tt;
     cin>>tt;
     while (tt--) {
         solve();
     }
}