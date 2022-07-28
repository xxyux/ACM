//
// Created by Xiangrui Yu on 2022/7/28.
//

// f1= b/a * d/c >1
// log(f1) >0
// log(b/a) + log(d/c) >0
//没有自增的路径 => 全部是负环
//每一条边取相反数之后
//全部是负环 => 没有负环

//一条边的边权乘w
// f2= b/a * w
// f2= log(b/a) + log(w)

#include "bits/stdc++.h"
using namespace std;
#define double long double

const int N=1010,M=2010;
const double eps=1e-9;
int h[N],e[M],ne[M],idx=0;
double f[M];
void add(int a,int b,double c) {
    e[idx]=b;ne[idx]=h[a];f[idx]=c;h[a]=idx++;
}
int n,m;

struct node{
    double dis;
    int cnt;

    void reset() {
        dis=0;
        cnt=0;
    }
}d[N];
int st[N];

bool check(double w) {
    queue<int> q;
    for(int i=1;i<=n;i++) {
        d[i].reset();
        st[i]=1;
        q.push(i);
    }
    while (!q.empty()) {
        int x=q.front();
        q.pop();
        st[x]=0;
        if(d[x].cnt>=n) return true;
        for(int i=h[x];~i;i=ne[i]) {
            int y=e[i];
            if(d[x].dis + w*(d[x].cnt+1) + f[i] < d[y].dis +w*d[y].cnt) {
                d[y].dis = d[x].dis + f[i];
                d[y].cnt = d[x].cnt + 1;
                if(st[y]==0) {
                    st[y]=1;
                    q.push(y);
                }
            }
        }
    }
    return false;
}

int main() {
    memset(h,-1,sizeof(h));
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        add(b,d,-log((double)c/a));
    }

    double l=0,r=1;
    while(r-l>eps) {
        double mid=(l+r)/2;
        if(check(-log(mid))) //返回true表示有负环，不能无限增加，尝试更小的w
            r=mid;
        else l=mid;
    }

    cout.setf(ios::fixed);
    cout.precision(10);
    cout<<l;
}