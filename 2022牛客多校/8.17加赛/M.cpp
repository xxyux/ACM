//
// Created by Xiangrui Yu on 2022/8/17.
//

#include "bits/stdc++.h"
using namespace std;

double a[4][5]={
        {1,1,0.8,0.5,0},
        {2,2,1.6,1.0,0},
        {3,3,2.4,1.5,0},
        {5,5,2.5,2,0}
};
double b[5]={1,0.5,0.4,0.3,0};

int main(){
    double A=0,A0=0,B=0,B0=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<5;j++) {
            int x;cin>>x;
            A0+=x*a[i][j];
            A+=x*a[i][0];
            if(i==3) {
                B0+=x*b[j];
                B+=x*b[0];
            }
        }
    cout<<setprecision(11)<<(A0/A+B0/B*0.01)*100;
}