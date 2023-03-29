//
// Created by Xiangrui Yu on 2023/3/29.
//
//修改数组 set
#include "bits/stdc++.h"
using namespace std;

const int N = 2000010;
set<int> s;

int main() {
    for(int i=1;i<N;i++) s.insert(i);
    int n;
    cin>>n;
    while (n--) {
        int x;
        cin>>x;
        set<int>::iterator p;
        p=s.lower_bound(x);
        cout<<*p<<' ';
        s.erase(p);
    }
}
/*
 5
 2 1 1 3 4
 */