#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve(){
    ll x;
    cin >> x;
    ll total_length;
    string s;
    cin >> s;
    total_length = s.length();
    ll l = 0;
    while(l != x){
        l++;
        ll pastes = s[l-1] - '0';
        ll start = l;
        ll end = s.length();
        for(int i = 0;i < pastes - 1;i++){
            if (s.length() < x){
                for(int j = start;j < end;j++){
                    s.push_back(s[j]);
                }
            }
        }
        ll copy_length = (BASE_NUM + total_length - l) % BASE_NUM;
        ll added = ((pastes - 1) * copy_length) % BASE_NUM;
        // cout << added << endl;
        total_length = (total_length + added) % BASE_NUM;
    }
    // cout << s << endl;
    cout << total_length << endl;
    return 0;
}
int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for(int i= 0;i< t;i++){
        solve();
        // string s = "";
        // for(int j = 0;j<1000000;j++){
        //     s.append("a");
        // }
    }
    return 0;
}
