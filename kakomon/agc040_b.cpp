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

ll satisfaction(ll N,vector<pair<ll,ll>> &ranges){
    vector<pair<ll,ll>> from_left(N);
    vector<pair<ll,ll>> from_right(N);
    from_left[0] = ranges[0];
    from_right[N-1] = ranges[N-1];
    for(int i = 1;i < N;i++){
        from_left[i] = {max(from_left[i-1].first, ranges[i].first),min(from_left[i-1].second, ranges[i].second)};
    }
    for(int i = N-2;i >= 0;i--){
        from_right[i] = {max(from_right[i+1].first, ranges[i].first),min(from_right[i+1].second, ranges[i].second)};
    }
    ll ans = 0;
    for(int i = 0;i < N-1;i++){
        ans = max(ans, max( from_left[i].second - from_left[i].first,0ll) + max( from_right[i+1].second - from_right[i+1].first,0ll));
    }
    return ans;
}
int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<pair<ll,ll>> ranges(N);
    ll max_range = 0;
    ll max_left = 0;
    ll min_right = numeric_limits<ll>::max();
    for(int i = 0;i < N;i++){
        cin >> ranges[i].first >> ranges[i].second;
        ranges[i].second++;
        max_range = max(max_range, ranges[i].second - ranges[i].first);
        max_left = max(max_left,ranges[i].first);
        min_right = min(min_right,ranges[i].second);
    }
    ll ans = max_range + max(0ll, min_right - max_left);
    sort(ranges.begin(),ranges.end(),[](pair<ll,ll> &l, pair<ll,ll> &r){
        if (l.second == r.second){
            return l.first < r.first;
        }else{
            return l.second < r.second;
        }
    });
    ans = max(ans,satisfaction(N,ranges));
    cout << ans << endl;
    return 0;
}