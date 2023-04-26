//
// Created by Xiangrui Yu on 2023/3/30.
//

#include "bits/stdc++.h"
using namespace std;

int get(int x1,int y1,int x2,int y2,
        int x3,int y3,int x4,int y4) {
    if(x1>x3) {
        swap(x1,x3);
        swap(y1,y3);
        swap(x2,x4);
        swap(y2,y4);
    }
    int l=max(0,x2-x3);
    l=min(l,x2-x1);
    l=min(l,x4-x3);
    int r=0;
    if(y1<y3) {
        r=max(r,y2-y3);
    }
    else r=max(r,y4-y1);
    r=min(r,y2-y1);
    r=min(r,y4-y3);
    return l*r;
}

int main() {
    int n,a,b;
    cin>>n>>a>>b;
    int res=0;
    while (n--) {
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        int t=get(x1,y1,x2,y2,0,0,a,b);
        res+=t;
//        cout<<t<<endl;
    }
    cout<<res;
}