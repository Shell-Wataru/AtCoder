#include <iostream>
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
#include <stack>

using namespace std;
using ll = long long;

ll point(vector<pair<ll,ll>> &balloons, ll l ,ll r){
    // cout << l << " " << r << endl;
    if (l+1 == r){
        return r;
    }
    ll M = balloons.size();
    ll center = (l+r)/2;
    priority_queue<ll,vector<ll>,greater<ll>> times;
    for(auto &p:balloons){
        if (center - p.first < 0){
            return point(balloons,center,r);
        }
        times.push( (center - p.first)/p.second);

    }
    ll must_hits = 0;
    // cout << "c:" << center << endl;
    for(ll i = 0;i < M;i++){
        while(!times.empty() && times.top() <= i){
            // cout << times.top() << endl;
            must_hits++;
            times.pop();
        }
        if (must_hits > i+1){
            return point(balloons,center,r);
        }
    }
    return point(balloons,l,center);
}

int solve(){
    ll N;
    cin >> N;
    vector<pair<ll,ll>> balloons(N);
    for(int i = 0;i < N;i++){
        cin >> balloons[i].first;
        cin >> balloons[i].second;
    }
    cout << point(balloons,0,numeric_limits<ll>::max()/4) << endl;
    return 0;
}

int main()
{
    // 整数の入力
    // ll T;
    // cin >> T;
    // for (size_t i = 0; i < T; i++)
    // {
        solve();
    // }
    // cout << flush;
    return 0;
}