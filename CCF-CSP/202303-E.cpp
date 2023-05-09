//
// Created by Xiangrui Yu on 2023/5/8.
//

#include "bits/stdc++.h"
using namespace std;
#define int long long
int n,m;
const int N = 200010;
int l[N],r[N];
int s[N];
map<pair<int,int>,int> mp;

int a[N];
bool cmp(int x,int y) {
    if(l[x]!=l[y]) return l[x]<l[y];
    return r[x]<r[y];
}
int p[N];
map<pair<int,int>,int> res_mp;

vector<int> to[N];
int st[N];
void get_to() {
    for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++) {
            if(j==i) continue;
            if(l[a[j]]>=l[a[i]]&&l[a[j]]<=r[a[i]]+1) {
                if(r[a[j]]>r[a[i]]) {
                    to[a[i]].push_back(a[j]);
                }
            }
        }
    }
}


signed main() {
    cin>>n>>m;
    for(int i=0;i<m;i++) cin>>l[i]>>r[i];
    if(m<=18) {
        for (int i = 0; i < (1 << m); i++) {
            for(int j=0;j<=19;j++) s[j]=0;
            for (int j = 0; j < m; j++) {
                if (i & (1 << j)) {
                    for(int k=l[j];k<=r[j];k++) s[k]=1;
                }
            }
            int cnt=0;
            for(int j=1;j<=18;j++) {
                if(s[j]==1&&s[j-1]==0) cnt++;
            }
            if(cnt==1) {
                int lb,rb;
                for(int j=1;j<=18;j++) {
                    if(s[j]==1&&s[j-1]==0) lb=j;
                }
                for(int j=1;j<=18;j++) {
                    if(s[j]==1&&s[j+1]==0) rb=j;
                }
                mp[{lb,rb}]=1;
            }
        }
        cout<<mp.size();
    }
    else if(m<=3000) {
        /*
         * todo
         */
        for(int i=0;i<m;i++) a[i]=i;
        sort(a,a+m,cmp);
        get_to();
        int ans=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<m;j++) st[j]=0;
            st[a[i]]=1;
            queue<int> q;
            q.push(a[i]);
            while (!q.empty()) {
                int top=q.front();
                q.pop();
                if(res_mp[{l[a[i]],r[top]}]==0) {
                    res_mp[{l[a[i]],r[top]}]=1;
                    ans++;
                }
                for(int j=0;j<to[top].size();j++) {
                    int y=to[top][j];
                    if(st[y]==0) {
                        q.push(y);
                    }
                    st[y]=1;
                }
            }
        }
        cout<<ans;
    }
    else {
        int ans=0;
        for(int i=0;i<m;i++) a[i]=i;
        sort(a,a+m,cmp);
        int rb=r[a[0]];
        int cnt=1;
        for(int i=1;i<m;i++) {
            if(l[a[i]]>rb+1) {
                ans+=(cnt*(cnt+1)/2);
                cnt=1;
                rb=r[a[i]];
            }
            else {
                cnt++;
                rb=r[a[i]];
            }
        }
        ans+=(cnt*(cnt+1)/2);
        cout<<ans;
    }
}
