//
// Created by Xiangrui Yu on 2022/10/5.
//

#include"bits/stdc++.h"
using namespace std;

const int N = 2005;
int f[N][N];

void solve() {
    string s;
    cin>>s;
    int n=s.length();
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) f[i][j]=-2;
    }
    s=" "+s;
    for(int i=2;i<=n;i+=2) {
        for(int j=1;j+i-1<=n;j++) {
            //j ~ j+i-1
            int l=j,r=j+i-1;
            if(i==2) {
                if(s[l]==s[r]) f[l][r]=0;
                else f[l][r]=1;
            }
            else {
                char a=s[l],b=s[r],c=s[l+1],d=s[r-1];
                //1
                if(f[l+2][r]==1&&f[l+1][r-1]==1) f[l][r]=1;
                if((a<c&&f[l+2][r]>=0|| f[l+2][r]>0)
                    &&(a<b&&f[l+1][r-1]>=0||f[l+1][r-1]>0)) f[l][r]=1;

                if(f[l][r-2]==1&&f[l+1][r-1]==1) f[l][r]=1;
                if((b<d&&f[l][r-2]>=0||f[l][r-2]>0)
                    &&(a>b&&f[l+1][r-1]>=0||f[l+1][r-1]>0)) f[l][r]=1;
                //0
                if(f[l][r]==-2) {
                    if (a == c && f[l + 2][r] == 0 ) f[l][r] = 0;
                    if(a == b && f[l + 1][r - 1] == 0) f[l][r]=0;
                    if (d == b && f[l][r - 2] == 0 ) f[l][r] = 0;
                }
                //-1
                if(f[l][r]==-2) f[l][r]=-1;
            }
        }
    }
//    for(int i=2;i<=n;i+=2) {
//        for(int j=1;j+i-1<=n;j++) {
//            cout<<j<<" "<<j+i-1<<" "<<f[j][j+i-1]<<endl;
//        }
//    }
    if(f[1][n]==1) cout<<"Alice\n";
    else if(f[1][n]==0) cout<<"Draw\n";
    else cout<<"Bob\n";
}

int main() {
    int t;
    cin>>t;
    while(t--) solve();

}