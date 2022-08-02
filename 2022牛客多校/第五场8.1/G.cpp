//
// Created by Xiangrui Yu on 2022/8/2.
//

#include <iostream>
#include <cstring>
//回文自动机
using namespace std;

using i64 = long long;

const int N = 1000010;

int n;
int tr[N][26];
int fail[N], len[N];
int idx, last;
char s[N];
int cnt[N];
int lastans;

int newnode(int l)
{
    len[idx] = l;
    return idx++;
}

void init()
{
    idx = last = 0;
    newnode(0), newnode(-1);
    s[0] = -1, fail[0] = 1;
}

int get_fail(int p, int i)
{
    while (s[i - len[p] - 1] != s[i]) p = fail[p];
    return p;
}

int insert(int i)
{
    int u = s[i] - 'a';
    int p = get_fail(last, i);
    if (!tr[p][u]) {
        int now = newnode(len[p] + 2);
        fail[now] = tr[get_fail(fail[p], i)][u];
        tr[p][u] = now;
        cnt[now] = cnt[fail[now]] + 1;
    }
    last = tr[p][u];
    return lastans = cnt[last];
}

int main()
{
    scanf("%lld", &n);
    scanf("%s", s + 1);
    init();
    int a = 0, b = 0, c = 0;
    for (int i = 1; i <= n; i++) {
        int t = insert(i);
        if (s[i] == 'k') a += t;
        if (s[i] == 'f') b += t;
        if (s[i] == 'c') c += t;
    }
    cout << a << ' ' << b << ' ' << c;
    return 0;
}