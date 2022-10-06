//
// Created by Xiangrui Yu on 2022/10/6.
//

#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

int n,k;
string s[N];
int cnt[N];
map<string,int> mp;

int main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        string a="";
        for(int j=1;j<=k;j++) {
            char c;
            cin>>c;
            a+=c;
        }
        s[i]=a;
        mp[a]=1;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i==j) continue;
            string a=s[i];
            string b=s[j];
            string c="";
            for(int z=0;z<k;z++) {
                if(a[z]==b[z]) c+=a[z];
                else {
                    for(int p=0;p<3;p++) {
                        char l='0'+p;
                        if(a[z]!=l&&b[z]!=l) {
                            c+=l;
                            break;
                        }
                    }
                }
            }
            //cout<<a<<" "<<b<<" "<<c<<endl;
            if(mp[c]) cnt[i]++;
        }
    }
    int res=0;
    for(int i=1;i<=n;i++) {
        //cout<<cnt[i]<<" ";
        cnt[i]/=2;
        res+=cnt[i]*(cnt[i]-1)/2;
    }
    cout<<res;
}