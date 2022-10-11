//
// Created by Xiangrui Yu on 2022/10/10.
//

#include "bits/stdc++.h"
using namespace std;

int q(int x,int y) {
    cout<<"? "<<x<<" "<<y<<endl;
    int res;
    cin>>res;
    return res;
}
int r(int x) {
    cout<<"! "<<x<<endl;
}

void solve() {
    int n;
    cin>>n;
    if(n==1) {
        int x=q(1,2);
        if(x==1) {
            r(1);
        }
        else r(2);
        return;
    }
    vector<int> v,t;
    for(int i=0;i<(1<<n);i++) v.push_back(i+1);
    while (v.size()>=4) {
        t.clear();
        for(int i=0;i<v.size();i+=4) {
            int a=v[i],b=v[i+1],c=v[i+2],d=v[i+3];
            int r1=q(a,c),r2;
            if(r1==0) {
                r2=q(b,d);
                if(r2==1) t.push_back(b);
                else t.push_back(d);
            }
            else if(r1==1) {
                r2=q(a,d);
                if(r2==1) t.push_back(a);
                else t.push_back(d);
            }
            else if(r1==2) {
                r2=q(b,c);
                if(r2==1) t.push_back(b);
                else t.push_back(c);
            }
        }
        v=t;
    }
    int a=v[0],b=v[1];
    int x=q(a,b);
    if(x==1) {
        r(a);
    }
    else r(b);
}

int main() {
    int tt;
    cin>>tt;
    while(tt--) solve();
}