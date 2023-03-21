//
// Created by Xiangrui Yu on 2023/3/21.
//

#include "bits/stdc++.h"
using namespace std;

void solve() {
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    string s1,s2;

    int p=s.length()-1;
    while (p>0&&s[p-1]==s[p]) p--;

    for(int i=0;i<s.length();i++) {
        int j=i+1;
        if(j<s.length()&&s[j]==s[i]) {
            s1+=s[i];
            s2+=s[j];
            i++;
        }
        else if(j<s.length()&&s[j]!=s[i]) {
           if(j==p) {
               int bac=s.length()-p;
               for(int k=0;k<bac/2;k++) s2+=s[p];
               s2+=s[i];
               for(int k=0;k<bac-bac/2;k++) s1+=s[p];
           }
           else {
               s1+=s[i];
               for(int k=i+1;k<s.length();k++) {
                   s2+=s[k];
               }
           }
            break;
        }
        else s1+=s[i];
    }
    reverse(s2.begin(),s2.end());
//    cout<<s<<" "<<s1<<" "<<s2<<endl;
    string res=s1+s2;
    string rev=res;
    reverse(rev.begin(),rev.end());
    cout<<max(rev,res)<<endl;
}

int main() {
    int tt;
    cin>>tt;
    while (tt--) solve();
}