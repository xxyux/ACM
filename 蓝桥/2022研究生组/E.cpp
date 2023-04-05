//
// Created by Xiangrui Yu on 2023/4/4.
//

#include "bits/stdc++.h"
using namespace std;

#define int long long

//gcd(a+k,b+k) = gcd(b-a,a+k)

signed main() {
    int a,b;
    cin>>a>>b;
    if(b-a<=a) {
        int c=b-a;
        a%=c;
        cout<<c-a;
    }
    else {
        cout<<b-a-a;
    }
}