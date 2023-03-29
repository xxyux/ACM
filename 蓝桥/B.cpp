//
// Created by Xiangrui Yu on 2023/3/26.
//
//分果果
#include "bits/stdc++.h"
using namespace std;

const int N =105;
int a[N];
int s[N];
int min_val[N*N];
int dp[N][N][N];

/*
 状态定义
 dp[i][j][k] 第i个小朋友获得的最后一个糖果是j，第i-1个小朋友获得的最后一个糖果是<=k时
 所有小朋友获得糖果数量最大值的最小值

 状态转移
 dp[i][j][k]=dp[i][j][k-1] 状态定义可知
 dp[i][j][k]=min(dp[i][j][k],max(dp[i-1][k][id],sum(a[id]...a[j]))
 第i个人用了前i-1个人中已经分配两次糖果编号的后某个位置开始
 */


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        for(int j=0;j<i;j++) {
            min_val[s[i]-s[j]]=1;
        }
    }
    int ans=0x3f3f3f3f;
    for(int mval=1;mval*m<=2*s[n];mval++) {//最小值的上界
        if(min_val[mval]==0) continue;//最小值不可能出现
        memset(dp,0x3f,sizeof dp);
        dp[0][0][0]=0;
        for(int i=1;i<=m;i++) {
            for(int k=0;k<=n;k++) {//i-1个人获得的最后一个糖果
                int id=0;//i-2个人获得的的最后一个糖果
                for(int j=k;j<=n;j++) {//i个人获得的最后一个糖果
                    if(k>0) dp[i][j][k]=dp[i][j][k-1];
                    if(s[j]<mval) continue;//小于最小值
                    while (id<k&&s[j]-s[id]>mval) id++;
                    if(s[j]-s[id]<mval) id--;
                    dp[i][j][k]=min(dp[i][j][k],max(dp[i-1][k][id],s[j]-s[id]));
                }
            }
        }
        ans=min(ans,dp[m][n][n]-mval);
    }
    cout<<ans;
}
/*
 5 2
6 1 2 7 9

 5 5
 6 1 2 7 9
 */
