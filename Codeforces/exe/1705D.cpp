//
// Created by Xiangrui Yu on 2022/10/15.
//

#include "bits/stdc++.h"
using namespace std;


void solve() {
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    if(s[0]!=t[0]||s.back()!=t.back()) {
        cout<<-1<<endl;
        return;
    }
    vector<int> pa,pb;
    for(int i=0;i<n-1;i++) {
        if(s[i]!=s[i+1]) pa.push_back(i);
        if(t[i]!=t[i+1]) pb.push_back(i);
    }
    if(pa.size()!=pb.size()) {
        cout<<-1<<endl;
        return;
    }
    long long res=0;
    for(int i=0;i<pa.size();i++) {
        res+=abs(pa[i]-pb[i]);
    }
    cout<<res<<endl;
}

int main() {
    int t;
    cin>>t;
    while (t--) solve();

}