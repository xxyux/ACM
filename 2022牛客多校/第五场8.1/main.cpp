#include<bits/stdc++.h>
using namespace std;

const int N=100010;
int a[N][2],n;
int b[N];

int main() {
    cin>>n;
    for(int i=1;i<=n*3;i++) {
        int x;cin>>x;x++;
        string s;cin>>s;
        if(s=="NO") a[x][0]++;
        else a[x][1]++;
    }
    vector<int> v;
    for(int i=1;i<=n;i++) {
        int x=a[i][0],y=a[i][1];
        if(x==y) {//01出现次数相等判断不了
            cout<<-1;
            return 0;
        }
        if(x>1&&y>1) {
            cout<<-1;
            return 0;
        }
        if(x>0&&y>0) v.push_back(i);
    }
    if(v.size()>1) cout<<-1;
    else if(v.size()==1) {
        for(int i=1;i<=n;i++) {
            if(i==v[0]) {
                if(a[i][0]>a[i][1]) cout<<0;
                else cout<<1;
            }
            else {
                if(a[i][0]>0) cout<<0;
                else cout<<1;
            }
        }
    }
    else {
        for(int i=1;i<=n;i++) {
            if(a[i][0]+a[i][1]==1) {
                cout<<-1;
                return 0;
            }
        }
        for(int i=1;i<=n;i++) {
            if(a[i][0]>0) cout<<0;
            else cout<<1;
        }
    }
}