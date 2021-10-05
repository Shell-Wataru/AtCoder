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
    ll N, M;
    cin >> N >> M;
    vector<pair<ll,ll>> works(N);
    for(int i = 0;i < N;i++){
        cin >> works[i].first >> works[i].second;
    }
    sort(works.rbegin(),works.rend());
    priority_queue<ll> q;
    ll ans = 0;
    for(int i = 1;i <= M;i++){
        while(!works.empty() && works.back().first <= i){
            q.push(works.back().second);
            works.pop_back();
        }
        if (!q.empty()){
            ans += q.top();
            q.pop();
        }
    }
    cout << ans << endl;
   return 0;
}