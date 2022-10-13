//
// Created by Xiangrui Yu on 2022/10/13.
//

#include "bits/stdc++.h"
using namespace std;
#define int long long

const int N = 200010;
int a[N],n;

bool cmp(pair<int,int> x,pair<int,int> y) {
    if(x.first!=y.first) return x.first>y.first;
    return x.second>y.second;
}

void solve() {
    cin>>n;
    vector<pair<int,int>> v;

    for(int i=1;i<=n;i++) {
        cin>>a[i];
        v.push_back({a[i],a[i]});
    }
    sort(v.begin(),v.end(),cmp);
    vector<int> v1,v2;
    int cur=0;
    for(int i=1;i<=n;i++) {
        if(v.size()==0) break;
        v1.push_back(v[0].second);
        cur|=v[0].first;

        vector<pair<int,int>> t;
        for(int j=1;j<v.size();j++) {
            int sum=0;
            for(int k=0;k<=30;k++) {
                if(((cur>>k)&1)==0) {
                    if((v[j].first>>k)&1) {
                        sum+=(1<<k);
                    }
                }
            }
            if(sum) {
                t.push_back({sum,v[j].second});
            }
            else v2.push_back(v[j].second);
        }
        v=t;
        sort(v.begin(),v.end(),cmp);
    }
    for(auto p:v1) cout<<p<<" ";//cout<<endl;
    for(auto p:v2) cout<<p<<" ";
    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--) {
        solve();
    }

}