//
// Created by Xiangrui Yu on 2022/10/7.
//
#include<bits/stdc++.h>
using namespace std;

#define int long long
int n;
int res=0;
vector<vector<int>> w,s;

int check(int x) {
    for(int i=0;i<w.size();i++) {
        int cnt1=0,cnt2=0;
        for(auto p:w[i]) {
            if(p&(1<<x)) cnt1++;
        }
        for(auto p:s[i]) {
            if(p&(1<<x)) cnt2++;
        }
        if(cnt1+cnt2!=w[i].size()) {
            return 0;
        }
    }
    return 1;
}
vector<vector<int>> w1,s1;
vector<int> p1,p2,l1,l2;
void dfs(int x) {
    int pos=-1;
    for(int i=x;i>=0;i--) {
        if(check(i)) {
            w1=w;s1=s;
            w.clear();s.clear();
            for(int j=0;j<w1.size();j++) {
                p1.clear();p2.clear();
                l1.clear();l2.clear();
                for(auto p:w1[j]) {
                    if(p&(1<<i)) p1.emplace_back(p);
                    else p2.emplace_back(p);
                }
                for(auto p:s1[j]) {
                    if(p&(1<<i)) l1.emplace_back(p);
                    else l2.emplace_back(p);
                }
                if(!p1.empty()) {
                    w.emplace_back(p1);
                    s.emplace_back(l2);
                }
                if(!p2.empty()) {
                    w.emplace_back(p2);
                    s.emplace_back(l1);
                }
            }
            res+=(1<<i);
            pos=i-1;
            break;
        }
    }
    if(pos>=0) dfs(pos);
}

void solve() {
    w.clear();
    s.clear();
    res=0;
    cin>>n;
    vector<int> a,b;
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        a.emplace_back(x);
    }
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        b.emplace_back(x);
    }
    w.emplace_back(a);
    s.emplace_back(b);
    dfs(29);
    cout<<res<<endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--) solve();
}
/*
 8
28 14 12 27 10 8 27 27
5 23 17 2 21 19 6 22
 */