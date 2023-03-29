//
// Created by Xiangrui Yu on 2023/3/26.
//
//双向排序
#include "bits/stdc++.h"
using namespace std;

int ans[100005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    stack<int> sk;
    while(m--) {
        int op,x;
        cin>>op>>x;
        if(op==0) {
            if(sk.size()%2!=op) {//0结尾
                if(!sk.empty()&&sk.top()<x) {
                    sk.pop();
                }
                else continue;
            }
            //保证此时以1结尾
            while (sk.size()>=2) {
                int t1=sk.top();sk.pop();
                int t0=sk.top();sk.pop();
                if(t0>x) {
                    sk.push(t0);
                    sk.push(t1);
                    break;
                }
            }
        }
        else {
            if(sk.size()%2!=op) {//1结尾
                if(!sk.empty()&&sk.top()>x) {
                    sk.pop();
                }
                else continue;
            }
            //保证此时以0结尾
            while (sk.size()>=2) {
                int t0=sk.top();sk.pop();
                int t1=sk.top();sk.pop();
                if(t1<x) {
                    sk.push(t1);
                    sk.push(t0);
                    break;
                }
            }
        }
        sk.push(x);
    }
    vector<int> v;
    while (!sk.empty()) {
        v.push_back(sk.top());
        sk.pop();
    }
    reverse(v.begin(),v.end());
//    for(auto p:v) cout<<p<<' ';
    int l=1,r=n;
    int x=n;
    for(int i=0;i<v.size();i++) {
        int mid=v[i];
        if(i%2==0) {//0 mid右边
            mid=max(l,mid);
            while (r>mid) ans[r--]=x--;
        }
        else {//1 mid左边
            mid=min(r,mid);
            while (l<mid) ans[l++]=x--;
        }
        if(r-l<1) break;
    }
    if(l<=r) {
        if(v.size()%2==1) {//0结尾
            while (l<=r) ans[l++]=x--;
        }
        else {//1结尾
            while (l<=r) ans[r--]=x--;
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}
/*
 3 3
0 3
1 2
0 2
 */