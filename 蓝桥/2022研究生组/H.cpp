//
// Created by Xiangrui Yu on 2023/4/4.
// 题目链接：
// https://www.acwing.com/problem/content/4652/


#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include "bits/stdc++.h"
using namespace std;

#define int long long
const int N = 200010;
const __int128 inf = 1e38;
int a[N],b[N],k[N];
int p[N];

int quadrant(int x,int y) {
    if(x>=0&&y>0) return 1;
    if(x>0&&y<=0) return 2;
    if(x<=0&&y<0) return 3;
    if(x<0&&y>=0) return 4;
}

int cross(int x1,int y1,int x2,int y2) {
    return x1*y2-x2*y1;
}

bool cmp(int x,int y) {
    int x1=a[x],y1=b[x];
    int x2=a[y],y2=b[y];

    int q1=quadrant(x1,y1);
    int q2=quadrant(x2,y2);
    if(q1!=q2) {
        return q1<q2;
    }
    else {
        int c=cross(x1,y1,x2,y2);
        if(c!=0) {
            return c<0;
        }
        else return x1*x1+y1*y1<x2*x2+y2*y2;
    }
}

struct node{
    int l,r;
    __int128 v;
};
node tr[N*4];
void pushup(int u) {
    tr[u].v=min(tr[u<<1].v,tr[u<<1|1].v);
}
void build(int u,int l,int r) {
    tr[u].l=l;tr[u].r=r;
    if(l==r) {
        tr[u].v=a[p[l]]*a[p[l]]+b[p[l]]*b[p[l]];
        return;
    }
    int mid=(l+r)/2;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}
__int128 query(int u,int l,int r) {
    if(tr[u].l>=l&&tr[u].r<=r) return tr[u].v;

    int mid=(tr[u].l+tr[u].r)/2;
    __int128 res=inf;
    if(l<=mid) res=min(res,query(u<<1,l,r));
    if(mid+1<=r) res=min(res,query(u<<1|1,l,r));
    return res;
}
void modify(int u,int l,__int128 x) {
    if(tr[u].l==tr[u].r) {
        tr[u].v=x;
        return;
    }
    int mid=(tr[u].l+tr[u].r)/2;
    if(l<=mid) modify(u<<1,l,x);
    else modify(u<<1|1,l,x);
    pushup(u);
}

int get(int lpos,int rpos,__int128 x) {//find [l,r]中第一个小于等于x的位置
    int l=lpos,r=rpos;
    while (l<r) {
        int mid=(l+r)/2;
        __int128 val=query(1,l,mid);
        if(val<=x*x) {
            r=mid;
        }
        else {
            l=mid+1;
        }
    }
    return l;
}

template <typename T> //快读模板
inline T fastread(T &x)
{
    x = 0;
    T w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x = x * w;
}

int res[N];
signed main() {
    int n,mm;

    fastread(n);fastread(mm);
    __int128 m=mm;
    for(int i=1;i<=n;i++) {
        fastread(a[i]);
        fastread(b[i]);
        fastread(k[i]);
        p[i]=i;
        res[i]=-1;
    }
    sort(p+1,p+1+n,cmp);
//    for(int i=1;i<=n;i++) cout<<p[i]<<" "; cout<<endl;
    build(1,1,n);
//    cout<<query(1,1,n)<<endl;
//    for(int i=1;i<4*n;i++) {
//        cout<<i<<' '<<tr[i].l<<" "<<tr[i].r<<" "<<tr[i].v<<endl;
//    }

    int pos=1;
    int num=0;
    while (1) {
        __int128 mr=query(1,pos,n);
        __int128 ml=query(1,1,pos);
        if(mr>m*m&&ml>m*m) break;

        int next;
        if(mr<=m*m) {
            int s=0;
            next=get(pos,n,m);
            m+=k[p[next]];
            res[p[next]]=num+1;
            s++;
            modify(1,next,inf);
            while (next<n&&cross(a[p[next]],b[p[next]],a[p[next+1]],b[p[next+1]])==0) {
                next++;
                m+=k[p[next]];
                res[p[next]]=num+1;
                s++;
                modify(1,next,inf);
            }
            num+=s;
            pos=next;
        }
        else pos=1;
    }
    for(int i=1;i<=n;i++) printf("%lld ",res[i]);
}