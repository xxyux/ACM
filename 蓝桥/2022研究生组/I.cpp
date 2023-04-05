// 题目链接：
// https://www.acwing.com/problem/content/description/4653/
#include "bits/stdc++.h"
using namespace std;

#define int long long

bool check(int x) {
    int l=1,r=2e9;
    while (l<r) {
        int mid=(l+r)/2;
        if(mid*mid<x) l=mid+1;
        else r=mid;
    }
    if(r*r==x) return true;
    l=1,r=2e6;
    while (l<r) {
        int mid=(l+r)/2;
        if(mid*mid*mid<x) l=mid+1;
        else r=mid;
    }
    if(r*r*r==x) return true;
    return false;
}

const int N = 4010;
int v[N]; // v[i]记录数字i的最小质因子
int prime[N], m;
void init() //线性筛
{
    memset(v, 0, sizeof v); // v[i]记录数字i的最小质因子
    m = 0;                  // m记录质数个数
    for (int i = 2; i <= 4000; ++i)
    {
        if (v[i] == 0) // i是质数
        {
            v[i] = i;
            prime[++m] = i;
        }
        for (int j = 1; j <= m; ++j)
        {
            //若i有比prime[j]更小的质因子，或超出n的范围，则停止循环
            if (prime[j] > v[i] || prime[j] > 4000 / i)
                break;
            // prime[j]是合数i*prime[j]的最小质因子
            v[i * prime[j]] = prime[j];
        }
    }
}

void solve() {
    int n;
    cin>>n;
    if(check(n)) {
        cout<<"yes\n";
        return;
    }
    for(int i=1;i<=m;i++) {
        int x=prime[i];
        if(n%x==0) {
            int cnt=0;
            while (n%x==0) {
                n/=x;
                cnt++;
            }
            if(cnt==1) {
                cout<<"no\n";
                return;
            }
        }
    }
    if(check(n)) cout<<"yes\n";
    else cout<<"no\n";
}

signed main() {
    init();
    int tt;
    cin>>tt;
    while (tt--) solve();
}