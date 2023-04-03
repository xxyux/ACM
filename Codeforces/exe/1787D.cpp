//
// Created by Xiangrui Yu on 2023/3/24.
//

#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 200010;
int a[N];
int b[N];
int f[N];
void get0(int x) {
    if(x==0) {
        b[x]=2;
        return;
    }
    if(b[x]) return;
    if(f[x]) {
        b[x]=1;
        return;
    }
    f[x]=1;
    get0(a[x]);
    b[x]=b[a[x]];
}

int f1[N];
int get1(int x) {
    if(a[x]==x) {
        return 1;
    }
    if(a[a[x]]==x) return 2;
    if(f1[x]==1) return 0;
    f1[x]=1;
    return get1(a[x])+1;
}
vector<int> v[N];
int c[N];
void get_fa(int x) {
    if(c[x]) return;
    for(auto p:v[x]) {
        get_fa(p);
        c[x]+=c[p];
        c[x]++;
    }
}
int ans=0;
void get2(int x,int n,int cnt) {
    if(x==0) return;
    ans+=(2*n+1-c[x]-cnt-1);
    get2(a[x],n,cnt);
}
void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        a[i]=i+a[i];
        if(a[i]<1||a[i]>n) a[i]=0;
        v[a[i]].push_back(i);
    }
    for(int i=1;i<=n;i++) get0(i);
    if(b[1]==2) {
        get_fa(0);
//        for(int i=1;i<=n;i++) cout<<c[i]<<" ";cout<<endl;
        int cnt=0;
        for(int i=1;i<=n;i++) {
            if(b[i]==1) cnt++;
        }
//        cout<<cnt<<endl;
        ans=0;
        get2(1,n,cnt);
        int len=0,x=1;
        while (x!=0) {
            len++;
            x=a[x];
        }
//        cout<<len<<endl;
        ans+=(n-len)*(2*n+1);
        cout<<ans<<endl;
    }
    else {
        int cnt=0;
        for(int i=1;i<=n;i++) {
            if(b[i]==2) cnt++;
        }
        int res=get1(1)*(2*n+1-(n-cnt));
        cout<<res<<endl;
    }
    for(int i=0;i<=n;i++) {
        b[i]=0;
        v[i].clear();
        c[i]=0;
        f[i]=0;
        f1[i]=0;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin>>tt;
    while (tt--) solve();
}