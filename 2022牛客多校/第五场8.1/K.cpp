//
// Created by Xiangrui Yu on 2022/8/2.
//

#include "bits//stdc++.h"
using namespace std;
//鸽巢原理
int main() {
    int n,k;
    cin>>n>>k;
    int x=n-k;
    if(x<=k) cout<<-1;
    else cout<<n+1;
}