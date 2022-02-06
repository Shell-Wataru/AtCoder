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
#include <cmath>

using namespace std;
using ll = long long;

int solve()
{
    ll N,Q;
    cin >> N >> Q;
    vector<ll> A(N);
    vector<ll> odd_sum(N+1,0);
    vector<ll> even_sum(N+1,0);
    for(int i = 0;i < N;i++){
        cin >> A[i];
        if (i % 2 == 1){
            odd_sum[i+1] = A[i];
        }else{
            even_sum[i+1] = A[i];
        }
    }
    for(int i = 0;i < N;i++){
        odd_sum[i+1] += odd_sum[i];
        even_sum[i+1] += even_sum[i];
    }

    vector<ll> Query(Q);
    for(int i = 0;i < Q;i++){
        cin >> Query[i];
    }
    vector<ll> sorted_query(Query);
    sort(sorted_query.begin(),sorted_query.end());
    vector<ll> x_gt(N,numeric_limits<ll>::min());
    for(int i = 1;i < (N+1)/2;i++){
        x_gt[N-i] = (A[N-i -1] + A[N-2*i -1])/2 + 1;
    }
    // for(int i = 0;i < N;i++){
    //     cout << x_gt[i] << endl;
    // }
    for(int i = 0;i < Q;i++){
        ll x = Query[i];
        ll index = upper_bound(x_gt.begin(),x_gt.end(),x) - x_gt.begin() - 1;
        // cout << x << ":" << index << endl;
        ll ans = odd_sum[N] - odd_sum[index] + even_sum[N] - even_sum[index];
        ll take = N - index;
        // cout  << "take" << take << endl;
        if (N % 2 == 0){
            ans += odd_sum[max(N-2*take,0ll)];
        }else{
            // cout << even_sum[max(N-2*take,0ll)] << endl;
            ans += even_sum[max(N-2*take,0ll)];
        }
        cout << ans << endl;
    }
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
