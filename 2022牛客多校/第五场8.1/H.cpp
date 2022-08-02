//
// Created by Xiangrui Yu on 2022/8/2.
//

#include<bits/stdc++.h>
using namespace std;

const double pi=acos(-1);
int main()
{
    double n;
    while(cin>>n)
    {
        n/=2;
        printf("%.9f\n",n*n*2+n*n*pi/2);
    }
    return 0;
}