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
    ll N,K;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    for(int i = 0;i < N;i++){
        cin >> B[i];
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    ll diff = 0;
    for(int i = 0;i < N;i++){
        diff += abs(A[i] - B[i]);
    }
    cout << diff << endl;
    return 0;
}