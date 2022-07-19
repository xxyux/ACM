//
// Created by Xiangrui Yu on 2022/7/19.
//

#include <bits/stdc++.h>
using namespace std;

const int N=100010;
vector<int> a[N];
void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) a[i].clear();

    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        a[x].push_back(i);
    }
    for(int i=1;i<=n;i++) {
        int res=0,k=0;
        for(auto p:a[i]) {
            if(res==0||p%2!=k) {
                res++;
                k=p%2;
            }
        }
        cout<<res<<' ';
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
