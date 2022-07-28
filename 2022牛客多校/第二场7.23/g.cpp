//
// Created by Xiangrui Yu on 2022/7/28.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int x;
        cin>>x;
        //10
        //4321 8765 109
        int y=sqrt(x);//每组的个数
        if(y*y<x) y++;
        int z=0;
        while (z<=x) {
            for(int i=y;i>=1;i--) {
                if(i+z<=x) cout<<i+z<<" ";
            }
            z+=y;
        }
        cout<<endl;
    }
}
