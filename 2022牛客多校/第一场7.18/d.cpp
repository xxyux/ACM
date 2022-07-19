//
// Created by Xiangrui Yu on 2022/7/19.
//

#include "bits/stdc++.h"
using namespace std;

#define double long double
#define int long long

signed main() {
    int t;
    scanf("%lld",&t);
    while(t--) {
        int r,x,y,d;
        scanf("%lld %lld %lld %lld",&r,&x,&y,&d);
        double u=sqrt(x*x+y*y);

        double L=acos((u+d)/r);
        double R=acos((u-d)/r);

        printf("%.10Lf\n",(R-L)*r);
    }
}
