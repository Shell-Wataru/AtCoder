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
    // 整数の入力
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    vector<ll> one_counts(61, 0);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            if (A[i] & 1ll << j)
            {
                one_counts[j]++;
            }
        }
    }
    vector<vector<ll>> DP(2, vector<ll>(61, 0));
    // DP[1][41] = numeric_limits<ll>::min();
    // 0:余裕なし
    // 1:余裕あり
    for (int i = 59; i >= 0; i--)
    {

        ll normal = (1ll << i) * one_counts[i];
        ll reversed = (1ll << i) * (N - one_counts[i]);
        if (K & 1ll << i)
        {
            // cout << reversed << endl;
            DP[0][i] = DP[0][i + 1] + reversed;
            DP[1][i] = max(DP[1][i], DP[0][i + 1] + normal);
            DP[1][i] = max(DP[1][i], DP[1][i + 1] + normal);
            if (K >= 1ll<<(i+1)){
                DP[1][i] = max(DP[1][i], DP[1][i + 1] + reversed);
            }
        }
        else
        {
            // cout << normal << endl;
            DP[0][i] = DP[0][i + 1] + normal;
            DP[1][i] = max(DP[1][i], DP[1][i + 1] + normal);
            if (K >= 1ll<<(i+1)){
                DP[1][i] = max(DP[1][i], DP[1][i + 1] + reversed);
            }

        }
    }
    // cout << "==" << endl;
    // cout << DP[0][0] << endl;
    // cout << DP[1][0] << endl;
    cout << max(DP[0][0], DP[1][0]) << endl;
    return 0;
}