//
// Created by Xiangrui Yu on 2022/10/5.
//

#include "bits/stdc++.h"
using namespace std;
#define int long long

int query(int x,int y) {
    cout<<"? "<<x<<" "<<y<<endl;
    int res;
    cin>>res;
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int r=1;;r++) {
        for(int l=1;l<r;l++) {
            int x=query(l,r);
            int y=query(r,l);
            if(x==-1||y==-1) {
                cout<<"! "<<r-1<<endl;
                return 0;
            }
            if(x!=y) {
                cout<<"! "<<x+y<<endl;
                return 0;
            }
        }
    }
}