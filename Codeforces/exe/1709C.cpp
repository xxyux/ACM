//
// Created by Xiangrui Yu on 2022/10/11.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 200010;

void solve() {
    string s;
    cin>>s;
    int n=s.length();
    int nop=0,ncl=0;
    for(auto p:s) {
        if(p=='(') nop++;
        if(p==')') ncl++;
    }
    nop=n/2-nop,ncl=n/2-ncl;
    int n1=-1,n2=-1;
    for(int i=0;i<n;i++) {
        if(s[i]=='?') {
            if(nop>0) {
                s[i]='(';
                n1=i;
                nop--;
            }
            else if(ncl>0) {
                s[i]=')';
                if(n2==-1) n2=i;
                ncl--;
            }
        }
    }
    if(n1==-1||n2==-1) {
        cout<<"YES\n";
        return;
    }
    swap(s[n1],s[n2]);
    //cout<<s<<endl;
    int bl=0;
    for(auto p:s) {
        if(p=='(') bl++;
        else bl--;
        if(bl<0) {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}

int main() {
    int t;
    cin>>t;
    while(t--) solve();
}