//
// Created by Xiangrui Yu on 2023/3/29.
//
//循环小数

#include "bits/stdc++.h"
using namespace std;

#define int long long

int gcd(int x,int y) {
    return x==0?y:gcd(y%x,x);
}

signed main() {
    int p,q;
    cin>>p>>q;
    int s;
    cin>>s;
    int bit=p-1;
    int res=s/pow(10,q-p+1);
    int a=pow(10,bit);
    int b=gcd(res,a);
    res/=b;
    a/=b;
    int c=s%(int)pow(10,q-p+1);
    int d=pow(10,q-p+1)-1;
    int e=gcd(c,d);
    c/=e;
    d/=e;
    d*=pow(10,p-1);
    e=gcd(c,d);
    c/=e;
    d/=e;
    //res/a + c/d
    int r1=res*d+a*c;
    int r2=a*d;
    cout<<r1/gcd(r1,r2)<<" "<<r2/gcd(r1,r2);

}