//
// Created by Xiangrui Yu on 2022/10/4.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 55;
int a[N][N];
int b[N][N];
int n,m;

bool check(int x,int y) {
    return x>=1&&x<=n&&y>=1&&y<=m;
}

bool check_L(int x,int y) {
    bool fl=true;
    int o=a[x][y],k=a[x+1][y],p=a[x][y+1],l=a[x+1][y+1];
    for(int i=x;i<=x+1;i++)
        for(int j=y;j<=y+1;j++)
            if(a[i][j]&&b[i][j]) fl=false;

    if(o&&k&&!p&&l) {
        bool f=true;
        for(int i=x-1;i<=x+2;i++) {
            for(int j=y-1;j<=y+2;j++) {
                if (i == x && j == y || i == x + 1 && j == y || i == x + 1 && j == y + 1 ||
                    i == x - 1 && j == y + 2)
                    continue;
                if (check(i, j)) {
                    if (a[i][j] == 1) f=false;
                    b[i][j]=1;
                }
            }
        }
        if(f&&fl) return true;
    }
    else if(!o&&k&&p&&l) {
        bool f=true;
        for(int i=x-1;i<=x+2;i++) {
            for(int j=y-1;j<=y+2;j++) {
                if (i == x && j == y+1 || i == x + 1 && j == y || i == x + 1 && j == y + 1 ||
                    i == x - 1 && j == y -1)
                    continue;
                if (check(i, j)) {
                    if (a[i][j] == 1) f=false;
                    b[i][j]=1;
                }
            }
        }
        if(f&&fl) return true;
    }
    else if(o&&k&&p&&!l) {
        bool f=true;
        for(int i=x-1;i<=x+2;i++) {
            for(int j=y-1;j<=y+2;j++) {
                if (i == x && j == y || i == x  && j == y+1 || i == x + 1 && j == y  ||
                    i == x + 2 && j == y + 2)
                    continue;
                if (check(i, j)) {
                    if (a[i][j] == 1) f= false;
                    b[i][j] = 1;
                }
            }
        }
        if(f&&fl) return true;
    }
    else if(o&&!k&&p&&l) {
        bool f=true;
        for(int i=x-1;i<=x+2;i++) {
            for(int j=y-1;j<=y+2;j++) {
                if (i == x && j == y || i == x  && j == y+1 || i == x + 1 && j == y+1  ||
                    i == x +2 && j == y -1)
                    continue;
                if (check(i, j)) {
                    if (a[i][j] == 1) f=false;
                    b[i][j]=1;
                }
            }
        }
        if(f&&fl) return true;
    }
    return false;
}
int c[N][N];

void solve() {
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            char c;
            cin>>c;
            if(c=='*') a[i][j]=1;
            else a[i][j]=0;
        }
    }
    for(int i=1;i<=n-1;i++) {
        for(int j=1;j<=m-1;j++) {
            if(check_L(i,j)) {
                c[i][j]=a[i][j];
                c[i][j+1]=a[i][j+1];
                c[i+1][j]=a[i+1][j];
                c[i+1][j+1]=a[i+1][j+1];
            }
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            //cout << c[i][j];
            if (a[i][j] != c[i][j]) {
                cout << "NO\n";
                return;
            }
        }
        //cout<<endl;
    }
    cout<<"YES\n";
}

int main() {
    int tt;
    cin>>tt;
    while (tt--) {
        solve();
    }
}