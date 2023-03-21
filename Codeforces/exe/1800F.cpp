//
// Created by Xiangrui Yu on 2023/3/21.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 1024*1024*64;
unordered_map<int,int> a;
int c[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    long long res=0;
    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;
        memset(c,0,sizeof(c));
        for(auto p:s) c[p-'a']++;

        for(int j=0;j<26;j++) {
            if(c[j]==0) {
                int cur=0;
                for(int k=0;k<26;k++) {
                    if(k!=j) {
                        cur+=((1-(c[k]&1))<<k);
                    }
                }
                res+=a[j*N+cur];
            }
        }

        int cur=0;
        for(int j=0;j<26;j++) {
            cur+=((c[j]&1)<<j);
        }
        for(int j=0;j<26;j++) {
            if(c[j]==0) a[j*N+cur]++;
        }
    }
    cout<<res;
}