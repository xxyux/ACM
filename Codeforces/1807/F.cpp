//
// Created by Xiangrui Yu on 2023/3/19.
//

#include "bits/stdc++.h"
using namespace std;

const int N = 200010;

map<long long,int> mp;

int dx[4]={1,1,-1,-1};
int dy[4]={1,-1,1,-1};

int check(int ax,int ay,int bx,int by,int cx,int cy) {
    if(ax==cx&&ay==cy) {
        if(ax!=bx||ay!=by) return 0;
        else return 1;
    }
    int x1=bx-ax,y1=by-ay;
    int x2=cx-bx,y2=cy-by;

    if(x1*y2==y1*x2&&x1*x2>=0&&y1*y2>=0) return 1;
    else return 0;
}

void solve() {
    int n,m,ax,ay,bx,by;
    string dr;
    cin>>n>>m>>ax>>ay>>bx>>by>>dr;

    mp.clear();
    int d;
    if(dr=="DL") d=1;
    if(dr=="DR") d=0;
    if(dr=="UL") d=3;
    if(dr=="UR") d=2;

    int res=0;
    int ff=1;
    while (1) {
        if(d==0) {
            int dis_x=n-ax;
            int dis_y=m-ay;
            int cx,cy;
            if(dis_x<dis_y) cx=n,cy=ay+dis_x,d=2;
            else if(dis_x>dis_y) cx=ax+dis_y,cy=m,d=1;
            else cx=n,cy=m,d=3;
            if(mp[(cx-1)*m+cy]==2) {
                ff=0;
                break;
            }
            if(check(ax,ay,bx,by,cx,cy)) break;
            res++;
            mp[(cx-1)*m+cy]++;
            ax=cx,ay=cy;
        }
        else if(d==1) {
            int dis_x=n-ax;
            int dis_y=ay-1;
            int cx,cy;
            if(dis_x<dis_y) cx=n,cy=ay-dis_x,d=3;
            else if(dis_x>dis_y) cx=ax+dis_y,cy=1,d=0;
            else cx=n,cy=1,d=2;
            if(mp[(cx-1)*m+cy]==2) {
                ff=0;
                break;
            }
            if(check(ax,ay,bx,by,cx,cy)) break;
            res++;
            mp[(cx-1)*m+cy]++;
            ax=cx,ay=cy;
        }
        else if(d==2) {
            int dis_x=ax-1;
            int dis_y=m-ay;
            int cx,cy;
            if(dis_x<dis_y) cx=1,cy=ay+dis_x,d=0;
            else if(dis_x>dis_y) cx=ax-dis_y,cy=m,d=3;
            else cx=1,cy=m,d=1;
            if(mp[(cx-1)*m+cy]==2) {
                ff=0;
                break;
            }
            if(check(ax,ay,bx,by,cx,cy)) break;
            res++;
            mp[(cx-1)*m+cy]++;
            ax=cx,ay=cy;
        }
        else if(d==3) {
            int dis_x=ax-1;
            int dis_y=ay-1;
            int cx,cy;
            if(dis_x<dis_y) cx=1,cy=ay-dis_x,d=1;
            else if(dis_x>dis_y) cx=ax-dis_y,cy=1,d=2;
            else cx=1,cy=1,d=0;
            if(mp[(cx-1)*m+cy]==2) {
                ff=0;
                break;
            }
            if(check(ax,ay,bx,by,cx,cy)) break;
            res++;
            mp[(cx-1)*m+cy]++;
            ax=cx,ay=cy;
        }
    }
    if(ff==0) cout<<-1<<endl;
    else cout<<res<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt=1;
    cin>>tt;
    while (tt--) {
        solve();
    }
}