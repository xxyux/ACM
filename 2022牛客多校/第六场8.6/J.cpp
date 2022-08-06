//
// Created by Xiangrui Yu on 2022/8/6.
//

#include<bits/stdc++.h>
using namespace std;

int main(){

    int T;
    cin >> T;
    while(T--){
        int a, b, c, x;
        cin >> a >> b >> c >> x;
        int t = a - 2 * b;
        if (t == 0){
            if (c == x || b - c == x) cout << "Yes" << '\n';
            else cout << "No" << '\n';
            continue;
        }
        if ((x - c) % t == 0 || (x + c - b) % t == 0) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }

}