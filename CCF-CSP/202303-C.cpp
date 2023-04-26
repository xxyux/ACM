//
// Created by Xiangrui Yu on 2023/4/26.
//

#include "bits/stdc++.h"
using namespace std;

//#define int long long

struct person {
    int id;
    unordered_map<int,int> data;
};
map<int,set<int>> att;
const int N = 2510;
person a[N];
int n,m;
vector<int> num[N];
int idx=0;
stack<int> sk;
string s;

bool check_simple(int l,int r) {
    if(s[l]!='&'&&s[l]!='|') return true;
    else return false;
}
int kd;
pair<int,int> check_kind(int l,int r) {// 1 -> :    2 -> ~
    int t=0;
    pair<int,int> res;
    for(int i=l;i<=r;i++) {
        if(s[i]==':') {
            kd=1;
            res.first=t;
            t=0;
        }
        else if(s[i]=='~') {
            kd=2;
            res.first=t;
            t=0;
        }
        else t=t*10+s[i]-'0';
    }
    res.second=t;
    return res;
}


void dfs(int l,int r) {
    if(check_simple(l,r)) {
        kd=0;
        pair<int,int> res=check_kind(l,r);
//        cout<<kd<<" "<<res.first<<" "<<res.second<<endl;
        if(kd==1) { //   :
            num[idx].clear();
            for(auto p:att[res.first]) {
                if(a[p].data[res.first]==res.second) num[idx].push_back(p);;
            }
//            for(int i=1;i<=n;i++) {
//                if(a[i].data[res.first]==res.second) {
//                    num[idx].push_back(i);
//                }
//            }
        }
        else {//    ~
            num[idx].clear();
            for(auto p:att[res.first]) {
                if(a[p].data[res.first]!=res.second) num[idx].push_back(p);;
            }

//            for(int i=1;i<=n;i++) {
//                int val=a[i].data[res.first];
//                if(val!=0&&val!=res.second) {
//                    num[idx].push_back(i);
//                }
//            }
        }
        sk.push(idx);
        idx++;
        return;
    }
    int op=0;// 1 -> &     2 -> |
    if(s[l]=='&') op=1;
    else op=2;

    int pos=l+1;//  match )'s position
    int val=0;
    for(int i=pos;i<=r;i++) {
        if(s[i]=='(') val++;
        if(s[i]==')') val--;
        if(val==0) {
            pos=i;
            break;
        }
    }

    dfs(l+2,pos-1);
    dfs(pos+2,r-1);
    int t1=sk.top();
    sk.pop();
    int t2=sk.top();
    sk.pop();

    set<int> res;
    if(op==1) { //  &
        num[idx].clear();
        int tl=0,tr=0;
        int len1=num[t1].size(),len2=num[t2].size();
        while (tl<len1&&tr<len2) {
            int val1=num[t1][tl],val2=num[t2][tr];
            if(val1==val2) {
                num[idx].push_back(val1);
                tl++;tr++;
            }
            else if(val1>val2) tr++;
            else tl++;
        }
    }
    else { //  |
//        cout<<t1<<" "<<t2<<endl;
        num[idx].clear();
        int tl=0,tr=0;
        int len1=num[t1].size(),len2=num[t2].size();
        while (tl<len1&&tr<len2) {
            int val1=num[t1][tl],val2=num[t2][tr];
            if(val1==val2) {
                num[idx].push_back(val1);
                tl++;tr++;
            }
            else if(val1>val2) {
                num[idx].push_back(val2);
                tr++;
            }
            else {
                num[idx].push_back(val1);
                tl++;
            }
        }
        while (tl<len1) {
            num[idx].push_back(num[t1][tl]);
            tl++;
        }
        while (tr<len2) {
            num[idx].push_back(num[t2][tr]);
            tr++;
        }
    }
    sk.push(idx);
    idx++;
}

signed main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i].id;
        int k;
        cin>>k;
        for(int j=1;j<=k;j++) {
            int x,y;
            cin>>x>>y;
            a[i].data[x]=y;
            att[x].insert(i);
        }
    }
    cin>>m;
    while (m--) {
        idx=0;
        cin>>s;
        dfs(0,s.length()-1);
        int t=sk.top();
        sk.pop();
        set<int> res;
        for(auto p:num[t]) {
            res.insert(a[p].id);
        }
        for(auto p:res) cout<<p<<" "; cout<<endl;
    }
}