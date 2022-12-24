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

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N,M;
    cin >> N >> M;
    map<ll,vector<ll>> A;
    for (int i = 0; i < M; i++)
    {
        ll w,h;
        cin >> w >> h;
        A[w].push_back(h);
    }
    // 最長増加部分列
    vector<ll> DP(M, numeric_limits<ll>::max());
    for(auto p:A){
        vector<pair<ll,ll>> insert_data;
        for(auto h:p.second){
            insert_data.push_back({h,lower_bound(DP.begin(), DP.end(), h) - DP.begin()});
        }
        for(auto d:insert_data){
            DP[d.second] = min(DP[d.second],d.first);
        }
    }
    ll longest = lower_bound(DP.begin(), DP.end(), numeric_limits<ll>::max()) - DP.begin();
    cout << longest << endl;
    return 0;
}