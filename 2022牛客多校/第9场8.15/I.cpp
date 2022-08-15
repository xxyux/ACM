//
// Created by Xiangrui Yu on 2022/8/15.
//

#include "bits/stdc++.h"
using namespace std;

const int N=8010,inf=0x3f3f3f3f;
int dp[N][N];
int n;
int a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int k=1;k<=n;k++) {
        stack<pair<int,int>> st;//pos mx
        for(int i=1;i<=n;i++) {
            dp[k][i]=dp[k-1][i-1]+a[i];
            if(k==1) dp[k][i]=max(dp[k][i],dp[k][i-1]);
            int mx=inf;
            while(st.size()&&a[st.top().first]<=a[i]) {
                if(k>1&&st.top().first>=k-1) mx=min(mx,st.top().second);
                st.pop();
            }
            st.push({i,min(mx,dp[k-1][i])});
            int &x=dp[k][i];
            x=min(x,mx+a[i]);

            auto y=st.top();
            st.pop();
            if(st.size()) {
                if(st.top().first>=k) x=min(x,dp[k][st.top().first]);
                //cout<<k<<' '<<i<<" "<<st.top().first<<" "<<dp[k][st.top().first]<<endl;
            }
            st.push(y);

         //   cout<<dp[k][i]<<' ';
        }
       // cout<<endl;
       cout<<dp[k][n]<<endl;
    }

}