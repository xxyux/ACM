#include<bits/stdc++.h>
using namespace std;

int n;

char c[100][100];

int main() {
    cin>>n;
    for(int i=1;i<=4*n+5;i++) {
        for(int j=1;j<=13*n+19;j++) {
            if(i==1||i==4*n+5||j==1|j==13*n+19) c[i][j]='*';
            else c[i][j]='.';
        }
    }

    int x=1+n+1,y=1+n+1+1;
    for(int i=1;i<=2*n+3;i++) {
        c[x+i-1][y]='@';
        c[x+i-1][y+i-1]='@';
    }
    y+=2*n+3-1;
    for(int i=1;i<=2*n+3;i++) {
        c[x+i-1][y]='@';
    }
    y+=n+1+1;
    for(int i=1;i<=2*n+3;i++) {
        c[x+i-1][y]='@';
    }
    for(int i=1;i<=2*n+3;i++) {
        c[x][y+i-1]='@';
    }
    for(int i=1;i<=2*n+3;i++) {
        c[x+n+1][y+i-1]='@';
    }
    y+=2*n+3-1;
    y+=n+1+1;
    for(int i=1;i<=2*n+3;i++) {
        c[x+i-1][y]='@';
    }
    for(int i=1;i<=2*n+3;i++) {
        c[x+2*n+3-1][y+i-1]='@';
    }
    y+=2*n+3-1;
    y+=n+1+1;
    for(int i=1;i<=2*n+3;i++) {
        c[x][y+i-1]='@';
    }
    for(int i=1;i<=n+2;i++) {
        c[x+i-1][y]='@';
    }
    for(int i=1;i<=2*n+3;i++) {
        c[x+n+2-1][y+i-1]='@';
    }
    for(int i=1;i<=n+2;i++) {
        c[x+n+2-1+i-1][y+2*n+3-1]='@';
    }
    for(int i=1;i<=2*n+3;i++) {
        c[x+2*n+3-1][y+i-1]='@';
    }
    for(int i=1;i<=4*n+5;i++) {
        for(int j=1;j<=13*n+19;j++) {
            cout<<c[i][j];
        }
        cout<<endl;
    }
}