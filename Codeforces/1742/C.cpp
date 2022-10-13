//
// Created by Xiangrui Yu on 2022/10/13.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 10;
char c[N][N];

void solve() {
    for(int i=1;i<=8;i++) {
        for(int j=1;j<=8;j++) {
            cin>>c[i][j];
        }
    }
//    for(int i=1;i<=8;i++) {
//        for(int j=1;j<=8;j++) {
//            cout<<c[i][j];
//        }
//        cout<<endl;
//    }
    for(int i=1;i<=8;i++) {
        int c1=0,c2=0;
        for(int j=1;j<=8;j++) {
            if(c[i][j]=='R') c1++;
            if(c[i][j]=='B') c2++;
        }
        if(c1==8) {
            cout<<"R\n";
            return;
        }
    }
    for(int i=1;i<=8;i++) {
        int c1=0,c2=0;
        for(int j=1;j<=8;j++) {
            if(c[j][i]=='R') c1++;
            if(c[j][i]=='B') c2++;
        }
        if(c2==8) {
            cout<<"B\n";
            return;
        }
    }
}

int main() {
    int t;
    cin>>t;
    while(t--) solve();
}