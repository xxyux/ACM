//
// Created by Xiangrui Yu on 2023/3/20.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 200010;
vector<int> v[N];
int a[N];

int m, p;
struct Node
{
    int l, r;
    int v;  // 区间[l, r]中的最大值
}tr[N * 4];

void pushup(int u)  // 由子节点的信息，来计算父节点的信息
{
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

void build(int u, int l, int r)
{
    tr[u] = {l, r};
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

int query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].v;   // 树中节点，已经被完全包含在[l, r]中了

    int mid = tr[u].l + tr[u].r >> 1;
    int v = 0;
    if (l <= mid) v = query(u << 1, l, r);
    if (r > mid) v = max(v, query(u << 1 | 1, l, r));

    return v;
}

void modify(int u, int x, int v)
{
    if (tr[u].l == x && tr[u].r == x) tr[u].v = v;
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

int b[N];
bool cmp(int x,int y) {
    return a[x]<a[y];
}
void solve() {
    int n;
    cin>>n;
    int mm=0;
    for(int i=1;i<=n;i++) {
        b[i]=i;
        v[i].clear();
        int k;
        cin>>k;
        int maxx=0;
        for(int j=1;j<=k;j++) {
            int x;
            cin>>x;
            if(x>maxx) {
                maxx=x;
                v[i].push_back(x);
            }
        }
        a[i]=maxx;
        mm=max(mm,maxx);
    }
    sort(b+1,b+1+n,cmp);
    for(int k=1;k<=n;k++) {
        int i=b[k];
        int maxx=0;
        for(int j=0;j<v[i].size();j++) {
            int x=v[i][j];
            int cur=query(1,1,x-1)+v[i].size()-j;
            maxx=max(maxx,cur);
        }
        if(maxx>query(1,a[i],a[i]))
            modify(1,a[i],maxx);
//        cout<<a[i]<<" "<<maxx<<endl;
    }
    cout<<query(1,1,mm)<<endl;
    for(int i=1;i<=n;i++) {
        for(auto x:v[i]) modify(1,x,0);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    build(1,1,200000);
    int tt;
    cin>>tt;
    while (tt--) solve();
}