//
// Created by Xiangrui Yu on 2023/3/19.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 100010;

int c[26];

void solve() {
    int n;
    cin>>n;
    for(int i=0;i<26;i++) c[i]=2;
    string s;
    cin>>s;
    int ff=1;
    for(int i=0;i<n;i++) {
        if(c[s[i]-'a']==2) {
            if(i==0) c[s[i]-'a']=0;
            else c[s[i]-'a']=1-c[s[i-1]-'a'];
        }
        else {
            if(i>0&&c[s[i]-'a']==c[s[i-1]-'a']) {
                ff=0;
            }
        }
    }
    if(ff) cout<<"YES\n";
    else cout<<"NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt=1;
    cin>>tt;
    while (tt--) {
        solve();
    }
}