#include "bits/stdc++.h"
using namespace std;

typedef long long LL;
const int N=1000010;
int d[N];//每一位为中间的最长回文串的半径
void manacher(string &a) {
    string t="$|";//扩展串
    for(auto p:a) {
        t+=p;t+='|';
    }
    int l=1,r=1;
    for(int i=1;i<t.size();i++) {
        int j=l+r-i;
        if(r>i) d[i]=min(d[j],j-l+1);
        while (t[i-d[i]]==t[i+d[i]]) {
            //更新r，可能产生新的回文字串
            d[i]++;
        }
        if(i+d[i]-1>r) {
            l=i-d[i]+1;
            r=i+d[i]-1;
        }
    }
    a=t;
}
int cnt[N];

int main() {
    int n;
    string s;
    cin>>n;
    cin>>s;
    manacher(s);
    int m=s.length()-1;
    for(int i=1;i<=m;i++) {
        cnt[i]++;
        cnt[i+d[i]]--;
    }
    for(int i=1;i<=m;i++) {
        cnt[i]+=cnt[i-1];
    }
    LL res1=0,res2=0,res3=0;
    for(int i=1;i<=m;i++) {
        if(s[i]=='k') res1+=cnt[i];
        if(s[i]=='f') res2+=cnt[i];
        if(s[i]=='c') res3+=cnt[i];
    }
    cout<<res1<<" "<<res2<<" "<<res3;

}