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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main()
{
    // cout << primes.size();
    // 整数の入力
    ll N,K;
    cin >> N >> K;
    vector<pair<ll,ll>> AB(N);
    priority_queue<ll> q;
    for(int i = 0;i < N;i++){
        cin >> AB[i].first >> AB[i].second;
        q.push(AB[i].second);
        q.push(AB[i].first - AB[i].second);
    }
    ll ans = 0;
    for(int i = 0;i < K;i++){
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
    return 0;
}