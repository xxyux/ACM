//
// Created by Xiangrui Yu on 2022/10/12.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 200010;
int a[N];
vector<int> p[9];

void solve() {
    for(int i=0;i<9;i++) p[i].clear();
    string s;
    cin>>s;
    int n=s.length();
    s=" "+s;
    int w,m;
    cin>>w>>m;
    for(int i=1;i<=n;i++) {
        a[i]=a[i-1]+s[i]-'0';
        int x=i-w+1;
        if(x>=1) {
            int y=(a[i]-a[x-1])%9;
            if(p[y].size()<2) p[y].push_back(x);
        }
    }
    while (m--) {
        int l,r,k;
        cin>>l>>r>>k;
        int v=(a[r]-a[l-1])%9;
        pair<int,int> res={n+1,n+1};
        for(int i=0;i<9;i++) {
            int j=((k-i*v)%9+9)%9;
            int p1,p2;
            if(i==j) {
                if(p[i].size()==2) p1=p[i][0],p2=p[i][1];
                else continue;
            }
            else {
                if(p[i].size()>=1&&p[j].size()>=1)
                    p1=p[i][0],p2=p[j][0];
                else continue;
            }
            if(p1<res.first) res={p1,p2};
            else if(p1==res.first&&p2<res.second) res={p1,p2};
        }
        if(res.first==n+1&&res.second==n+1) cout<<-1<<" "<<-1<<endl;
        else cout<<res.first<<' '<<res.second<<endl;
    }

}

int main() {
    int t;
    cin>>t;
    while(t--) solve();
}