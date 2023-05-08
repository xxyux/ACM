//
// Created by Xiangrui Yu on 2023/5/8.
//

#include "bits/stdc++.h"
using namespace std;

const int N = (1<<16);
int a[N];
int n,q;

int get_num(char c) {
    if(c>='0'&&c<='9') return c-'0';
    else return c-'a'+10;
}

int get_pos(string s) {
    int res=0;
    for(int i=0;i<s.length();i++) {
        res=res*16+get_num(s[i]);
    }
    return res;
}

int main() {
    cin>>n>>q;
    while (q--) {
        int ty,id=0;
        string l,r,pos;
        cin>>ty;
        if(ty==1) cin>>id;
        if(ty==2) cin>>pos;
        else cin>>l>>r;

        int l_pos,r_pos,q_pos;
        if(ty==2) q_pos=get_pos(pos);
        else {
            l_pos=get_pos(l);
            r_pos=get_pos(r);
        }

        if(ty==1) {
            int flag_other=0,flag_0=0;
            for(int i=l_pos;i<=r_pos;i++) {
                if(a[i]!=0&&a[i]!=id) flag_other=1;
                if(a[i]==0) flag_0=1;
            }
            if(flag_other==1||flag_0==0) cout<<"NO\n";
            else {
                cout<<"YES\n";
                for(int i=l_pos;i<=r_pos;i++) a[i]=id;
            }
        }
        if(ty==2) {
            if(a[q_pos]==0) cout<<0<<endl;
            else cout<<a[q_pos]<<endl;
        }
        if(ty==3) {
            int flag_to=1;
            if(a[l_pos]==0) flag_to=0;
            for(int i=l_pos+1;i<=r_pos;i++) {
                if(a[i]!=a[l_pos]) flag_to=0;
            }
            if(flag_to==0) cout<<0<<endl;
            else cout<<a[l_pos]<<endl;
        }
    }
}