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
#include <unordered_map>

using namespace std;
using ll = long long;

int main()
{
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    A.push_back((X + A[N - 1] - 1) / A[N - 1] * A[N - 1] + A[N - 1]);

    unordered_map<ll, ll> dp;
    dp[0] = 1;
    for (int i = 0; i < N-1; i++)
    {
        unordered_map<ll, ll> next_dp;
        for (auto p : dp)
        {
            ll t = X - p.first;
            ll mod = A[i+1];
            ll range = A[i+1]/A[i];
            ll a;
            if (t < 0){
                a = ( (mod - (-t) % mod) % mod )/A[i];
            }else if (t == 0){
                a = 0;
            }else{
                a = ( t % mod )/A[i];
            }
            if (a == 0){
                next_dp[p.first] += p.second;
            }else{
                next_dp[p.first+a*A[i]] += p.second;
                next_dp[p.first-(range-a)*A[i]] += p.second;
            }

        }
        swap(dp, next_dp);
    }

    ll ans = 0;
    for (auto p : dp)
    {
        if ((p.first - X) % A[N-1] == 0 )
        {
            ans += p.second;
        }
    }
    cout << ans << endl;
    return 0;
}
