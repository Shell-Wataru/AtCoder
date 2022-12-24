#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;

ll plus_first(ll N,priority_queue<vector<ll>> ls,priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> rs){
    // cout << ls.size() << "," << rs.size() << endl;
    vector<bool> used(N,false);
    ll ans = 0;
    ll current = 0;
    ll last_addition = 0;
    while(true){
        while(!ls.empty() && used[ls.top().back()]){
            ls.pop();
        }
        if (ls.empty()){
            break;
        }
        if (ls.top().front() > current){
            ans += 2*ls.top().front();
            last_addition = 2*ls.top().front();
            current = ls.top().front();
            used[ls.top().back()] = true;
            ls.pop();
        }else{
            if (last_addition < 0){
                ans -= last_addition;
            }
            break;
        }
        while(!rs.empty() && used[rs.top().back()]){
            rs.pop();
        }
        if (rs.empty()){
            break;
        }
        if (rs.top().front() < current){
            ans += - 2*rs.top().front();
            last_addition = - 2*rs.top().front();
            current = rs.top().front();
            used[rs.top().back()] = true;
            rs.pop();
        }else{
            break;
        }
    }
    return ans;
}

ll minus_first(ll N,priority_queue<vector<ll>> ls,priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> rs){
    // cout << ls.size() << "," << rs.size() << endl;
    vector<bool> used(N,false);
    ll ans = 0;
    ll current = 0;
    ll last_addition = 0;
    while(true){
        while(!rs.empty() && used[rs.top().back()]){
            rs.pop();
        }
        if (rs.empty()){
            break;
        }
        if (rs.top().front() < current){
            ans += - 2*rs.top().front();
            last_addition = - 2*rs.top().front();
            current = rs.top().front();
            used[rs.top().back()] = true;
            rs.pop();
        }else{
            if (last_addition < 0){
                ans -= last_addition;
            }
            break;
        }

        while(!ls.empty() && used[ls.top().back()]){
            ls.pop();
        }
        if (ls.empty()){
            break;
        }
        if (ls.top().front() > current){
            ans += 2*ls.top().front();
            last_addition = 2*ls.top().front();
            current = ls.top().front();
            used[ls.top().back()] = true;
            ls.pop();
        }else{
            break;
        }
    }
    return ans;
}
int solve()
{
    ll N;
    cin >> N;
    priority_queue<vector<ll>> ls;
    priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> rs;

    for(int i = 0;i < N;i++){
        ll l,r;
        cin >> l >> r;
        ls.push({l,-r,i});
        rs.push({r,-l,i});
    }
    cout << max(plus_first(N,ls,rs),minus_first(N,ls,rs)) << endl;
    return 0;
}

int main()
{
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    // cout << flush;
    return 0;
}
