//
// Created by Xiangrui Yu on 2022/7/19.
//

#include <bits/stdc++.h>
using namespace std;

const int N=100;
int a[N];
void solve() {
    memset(a,0,sizeof(a));
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        int y=m+1-x;
        if(x<y) {
            if(a[x]==0) {
                a[x]=1;
            }
            else if(a[y]==0) a[y]=1;
        }
        else {
            if(a[y]==0) {
                a[y]=1;
            }
            else if(a[x]==0) a[x]=1;
        }
    }
    for(int i=1;i<=m;i++) {
        if(a[i]==0) cout<<'B';
        else cout<<'A';
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
}
