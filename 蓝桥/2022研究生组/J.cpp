//
// Created by Xiangrui Yu on 2023/4/4.
//

#include "bits/stdc++.h"
using namespace std;

//#define int long long
const int N = 100010;
int a[N];
int l[N],r[N],k[N];
int b[N];
int sq;

bool cmp(int x,int y) {
    if(l[x]/sq!=l[y]/sq) return l[x]<l[y];
    if(l[x]/sq&1) return r[x]<r[y];
    return r[x]>r[y];
}

int num[N];
int res[N];
int ans[N];

signed main() {
    int n,m;
    scanf("%d",&n);
    sq=sqrt(n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++) {
        b[i]=i;
        scanf("%d%d%d",&l[i],&r[i],&k[i]);
    }
    sort(b+1,b+1+m,cmp);

//    for(int i=1;i<=m;i++) cout<<b[i]<<" ";cout<<endl;

    int ll=1,rr=0;
    for(int i=1;i<=m;i++) {
        int x=b[i];

        while (ll>l[x]) {
            ll--;
            if(rr>=ll) {
                num[a[ll]]++;
                int y=num[a[ll]];
                res[y]++;
                res[y-1]--;
            }
        }

        while (ll<l[x]) {
            if(ll<=rr) {
                num[a[ll]]--;
                int y=num[a[ll]];
                res[y]++;
                res[y+1]--;
            }
            ll++;
        }

        while (rr<r[x]) {
            rr++;
            if(rr>=ll) {
                num[a[rr]]++;
                int y=num[a[rr]];
                res[y]++;
                res[y-1]--;
            }
        }
        while (rr>r[x]) {
            if(ll<=rr) {
                num[a[rr]]--;
                int y=num[a[rr]];
                res[y]++;
                res[y+1]--;
            }
            rr--;
        }

        ans[x]=res[k[x]];
    }
    for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
}