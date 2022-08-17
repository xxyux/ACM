//
// Created by Xiangrui Yu on 2022/8/17.
//

#include "bits/stdc++.h"
using namespace std;

#define int long long
const int N=1000010;
int d[N];
vector<pair<int,int>> v;//不同的回文串左右端点，不超过n个
void manacher(string &a) {
    string t="$|";
    for(auto p:a) {
        t+=p;
        t+='|';
    }
    int m=t.length()-1;
    int l=1,r=1;
    for(int i=1;i<=m;i++) {
        int j=l+r-i;
        if(i<r) d[i]=min(d[j],j-l+1);
        while (t[i-d[i]]==t[i+d[i]]) {
            if(t[i-d[i]]!='|') v.push_back({i-d[i],i+d[i]});
            d[i]++;
        }
        if(i+d[i]-1>r) {
            l=i-d[i]+1;
            r=i+d[i]-1;
        }
    }
    a=t;
}
int hash1[N],hash2[N];
int p1[N],p2[N];
const int base1=131,base2=13331;
const int mod1=998244353,mod2=1e9+7;
int get_hash1(int l,int r) {
    return (hash1[r]-hash1[l-1]*p1[r-l+1]%mod1+mod1)%mod1;
}
int get_hash2(int l,int r) {
    return (hash2[r]-hash2[l-1]*p2[r-l+1]%mod2+mod2)%mod2;
}

set<pair<int,int>> res,tmp,dis;
signed main() {
    int k;cin>>k;
    for(int i=1;i<=k;i++) {
        string s;
        cin>>s;
        v.clear();
        memset(d,0,sizeof(d));

        manacher(s);
        int n=s.length()-1;
        p1[0]=p2[0]=1;
        for(int j=1;j<=n;j++) {
            p1[j]=p1[j-1]*base1%mod1;
            p2[j]=p2[j-1]*base2%mod2;
            hash1[j]=(hash1[j-1]*base1%mod1+s[j])%mod1;
            hash2[j]=(hash2[j-1]*base2%mod2+s[j])%mod2;
        }
        tmp.clear();
        for(auto p:v) {
            tmp.insert({get_hash1(p.first,p.second),get_hash2(p.first,p.second)});
        }
        if(i==1) res=tmp;
        else {
            dis.clear();
            for(auto p:res) {
                if(tmp.find(p)==tmp.end()) {
                    dis.insert(p);
                }
            }
            for(auto p:dis) res.erase(p);
        }
    }
    cout<<res.size();
}