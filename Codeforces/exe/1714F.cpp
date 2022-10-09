//
// Created by Xiangrui Yu on 2022/10/9.
//

#include "bits/stdc++.h"
using namespace std;

void add(int x,int y) {
    cout<<x<<' '<<y<<endl;
}

void solve() {
    int n,d12,d23,d13;
    cin>>n>>d12>>d23>>d13;

    if((d12+d23-d13)%2==1) {
        cout<<"NO\n";
        return;
    }
    if(d12==1&&abs(d23-d13)!=1) {
        cout<<"NO\n";
        return;
    }
    if(d13==1&&abs(d23-d12)!=1) {
        cout<<"NO\n";
        return;
    }
    if(d23==1&&abs(d12-d13)!=1) {
        cout<<"NO\n";
        return;
    }

    int x=(d12+d23-d13)/2;
    int y=d12-x;
    int z=d23-x;
    if(y+z!=d13) {
        cout<<"NO\n";
        return;
    }
    //cout<<x<<" "<<y<<" "<<z<<endl;
    if(x<0||y<0||z<0) {
        cout<<"NO\n";
        return;
    }

    int idx=4;
    if(x==0) {
        if(y+z+1<=n) cout<<"YES\n";
        else {
            cout<<"NO\n";
            return;
        }
        vector<int> res;
        res.push_back(2);
        for(int i=1;i<=y-1;i++) res.push_back(idx++);
        res.push_back(1);
        for(int i=0;i<res.size()-1;i++) add(res[i],res[i+1]);
        res.clear();
        res.push_back(2);
        for(int i=1;i<=z-1;i++) res.push_back(idx++);
        res.push_back(3);
        for(int i=0;i<res.size()-1;i++) add(res[i],res[i+1]);
        while (idx<=n) {
            add(idx,1);
            idx++;
        }
        return;
    }
    if(y==0) {
        if(x+z+1<=n) cout<<"YES\n";
        else {
            cout<<"NO\n";
            return;
        }
        vector<int> res;
        res.push_back(1);
        for(int i=1;i<=x-1;i++) res.push_back(idx++);
        res.push_back(2);
        for(int i=0;i<res.size()-1;i++) add(res[i],res[i+1]);
        res.clear();
        res.push_back(1);
        for(int i=1;i<=z-1;i++) res.push_back(idx++);
        res.push_back(3);
        for(int i=0;i<res.size()-1;i++) add(res[i],res[i+1]);
        while (idx<=n) {
            add(idx,1);
            idx++;
        }
        return;
    }
    if(z==0) {
        if(x+y+1<=n) cout<<"YES\n";
        else {
            cout<<"NO\n";
            return;
        }
        vector<int> res;
        res.push_back(3);
        for(int i=1;i<=x-1;i++) res.push_back(idx++);
        res.push_back(2);
        for(int i=0;i<res.size()-1;i++) add(res[i],res[i+1]);
        res.clear();
        res.push_back(3);
        for(int i=1;i<=y-1;i++) res.push_back(idx++);
        res.push_back(1);
        for(int i=0;i<res.size()-1;i++) add(res[i],res[i+1]);
        while (idx<=n) {
            add(idx,1);
            idx++;
        }
        return;
    }
    int nd=x-1+y-1+z-1+4;
    if(nd>n) {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    idx=5;
    vector<int> res;
    res.push_back(4);
    for(int i=1;i<=x-1;i++) {
        res.push_back(idx);
        idx++;
    }
    res.push_back(2);
    for(int i=0;i<res.size()-1;i++) add(res[i],res[i+1]);

    res.clear();
    res.push_back(4);
    for(int i=1;i<=y-1;i++) {
        res.push_back(idx);
        idx++;
    }
    res.push_back(1);
    for(int i=0;i<res.size()-1;i++) add(res[i],res[i+1]);

    res.clear();
    res.push_back(4);
    for(int i=1;i<=z-1;i++) {
        res.push_back(idx);
        idx++;
    }
    res.push_back(3);
    for(int i=0;i<res.size()-1;i++) add(res[i],res[i+1]);

    while (idx<=n) add(idx++,1);
}

int main() {
//    int sum=0;
//    for(int i=3;i<=8;i++) {
//        int j=i-1;
//        sum+=j*j*j;
//        cout<<i<<" "<<sum<<endl;
//    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout.tie(0);
    int tt;
    cin>>tt;
    while (tt--) solve();
}