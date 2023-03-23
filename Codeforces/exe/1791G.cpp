#include "bits/stdc++.h"
using namespace std;

const int N = 200005;

int a[N],l[N],r[N];
long long s[N];

int get(int n,int m) {
    if(m<s[1]) return 0;
    int l=1,r=n;
    while (l<r) {
        int mid=(l+r)/2;
        if(mid==l) {
            if(s[r]<=m) l=r;
            else r=l;
        }
        else if(s[mid]<=m) l=mid;
        else r=mid-1;
    }
    return l;
}
int b[N];

bool cmp(int x,int y) {
    return min(l[x],r[x])<min(l[y],r[y]);
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) b[i]=i;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        l[i]=a[i]+i;
        r[i]=a[i]+n-i+1;
    }
    sort(b+1,b+1+n,cmp);
    for(int i=1;i<=n;i++) {
        s[i]=s[i-1]+min(l[b[i]],r[b[i]]);
    }
//    for(int i=1;i<=n;i++) cout<<b[i]<<' '; cout<<endl;
//    for(int i=1;i<=n;i++) cout<<s[i]<<" ";cout<<endl;
    int res=0;
    for(int i=1;i<=n;i++) {
        int x=b[i];
        if(m<l[x]) continue;

        int p=get(n,m-l[x]);
        if(p>=i-1) {
            p=get(n,m-l[x]+min(l[x],r[x]));
        }
        else p++;
        res=max(res,p);
//        cout<<i<<" "<<m-l[x]+min(l[x],r[x])<<' '<<p<<endl;
    }
    cout<<res<<endl;
}

int main() {
    int tt;
    cin>>tt;
    while (tt--) solve();
}