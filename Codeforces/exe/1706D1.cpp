//
// Created by Xiangrui Yu on 2022/10/12.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 3010;
int a[N],n,k;
set<int> s[N];

bool check(int x) {
    for(int l=0;l<=3000;l++) {
        int r=l+x;
        int f=1;
        for(int i=1;i<=n;i++) {
            auto p=s[i].lower_bound(l);
            if(p==s[i].end()) f=0;
            else {
                if(*p>r) f=0;
            }
        }
        if(f==1) return true;
    }
    return false;
}

void solve() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        s[i].clear();
        for(int j=1;j<=k;j++) s[i].insert(a[i]/j);
    }
//    cout<<check(13)<<endl;
    int l=0,r=3000;
    while (l<r) {
        int mid = (l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
//        cout<<l<<' '<<r<<endl;
    }
    cout<<r<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}