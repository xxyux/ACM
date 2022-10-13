//
// Created by Xiangrui Yu on 2022/10/13.
//

#include "bits/stdc++.h"
using namespace std;

#define int long long
int a[26],b[26];

void solve() {
    int q;
    cin>>q;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    a[0]=1;
    b[0]=1;
    int sa=1,sb=1;
    while (q--) {
        int x,y;
        cin>>x>>y;
        string s;
        cin>>s;
        if(x==1) {
            for(auto p:s) {
                a[p-'a']+=y;
            }
            sa+=y*s.length();
        }
        else {
            for(auto p:s) {
                b[p-'a']+=y;
            }
            sb+=y*s.size();
        }
        int maxp=26;
        for(int i=25;i>=0;i--) {
            if(b[i]) {
                maxp=i;
                break;
            }
        }
        if(maxp>0) {
            cout<<"YES\n";
        }
        else {
            if(a[0]==sa&&sa<sb) {
                cout<<"YES\n";
            }
            else cout<<"NO\n";
        }

    }
}

signed main() {
    int t;
    cin>>t;
    while(t--) solve();
}