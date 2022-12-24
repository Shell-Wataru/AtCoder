#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N,D;
    cin >> N >> D;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
    for(int i = 0;i < N;i++){
        ll l,r;
        cin >> l >> r;
        q.push({r,l});
    }
    ll broken = -1;
    ll ans = 0;
    while(!q.empty()){
        ll l = q.top().second;
        ll r = q.top().first;
        // cout << l << "~" << r << endl;
        q.pop();
        if (l <= broken){
            continue;
        }else{
            ans++;
            broken = r + D - 1;
        }
    }
    cout << ans << endl;
    return 0;
}