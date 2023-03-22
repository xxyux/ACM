//
// Created by Xiangrui Yu on 2023/3/22.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 200005;
int p[N],q[N];
int pos1[N],pos2[N];

int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>p[i];
        pos1[p[i]]=i;
    }
    for(int i=1;i<=n;i++) {
        cin>>q[i];
        pos2[q[i]]=i;
    }

    long long res=1;
    int p1=min(pos1[1],pos2[1]);
    int p2=max(pos1[1],pos2[1]);
    long long len1=p1-1,len2=p2-p1-1,len3=n-p2;
    if(len1>0) res+=(len1+1)*len1/2;
    if(len2>0) res+=(len2+1)*len2/2;
    if(len3>0) res+=(len3+1)*len3/2;


//    cout<<1<<" "<<res<<endl;

    int l1=pos1[1],r1=pos1[1];
    int l2=pos2[1],r2=pos2[1];
    int mex1=1,mex2=1;

    for(int i=2;i<=n;i++) {
        int x=pos1[i];

        int l11,l12,r11,r12;
        int l21,l22,r21,r22;
//        cout<<"lr: "<<i<<" "<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
        if(x<l1) {
            l11=x+1;
            r11=l1;
            l12=r1;
            r12=n;
            mex1=i;
        }
        else if(x>l1&&x<r1) {
            l11=1;
            r11=l1;
            l12=r1;
            r12=n;
        }
        else {
            l11=1;
            r11=l1;
            l12=r1;
            r12=x-1;
            mex1=i;
        }

        l1=min(l1,x);
        r1=max(r1,x);

        x=pos2[i];
        if(x<l2) {
            l21=x+1;
            r21=l2;
            l22=r2;
            r22=n;
            mex2=i;
        }
        else if(x>l2&&x<r2) {
            l21=1;
            r21=l2;
            l22=r2;
            r22=n;
        }
        else {
            l21=1;
            r21=l2;
            l22=r2;
            r22=x-1;
            mex2=i;
        }

        l2=min(l2,x);
        r2=max(r2,x);

        long long x1=min(r11,r21)-max(l11,l21)+1;
        long long x2=min(r12,r22)-max(l12,l22)+1;
        if(x1>0&&x2>0&&mex1==mex2&&mex1==i) {
//            cout<<i<<" "<<x1*x2<<endl;
            res+=x1*x2;
        }
//        cout<<res<<endl;
    }
    cout<<res;
}