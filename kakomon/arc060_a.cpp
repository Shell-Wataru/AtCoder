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
    ll N, A;
    cin >> N >> A;
    ll zero_count = 0;
    vector<ll> plus_numbers;
    vector<ll> minus_numbers;
    for (int i = 0; i < N; i++)
    {
        ll x;
        cin >> x;
        x -= A;
        if (x == 0)
        {
            zero_count++;
        }
        else if (x > 0)
        {
            plus_numbers.push_back(abs(x));
        }
        else
        {
            minus_numbers.push_back(abs(x));
        }
    }
    vector<vector<ll>> plusDP(plus_numbers.size() + 1, vector<ll>(50 * 50, 0));
    vector<vector<ll>> minusDP(minus_numbers.size() + 1, vector<ll>(50 * 50, 0));
    plusDP[0][0] = 1;
    minusDP[0][0] = 1;
    for (int i = 0; i < plus_numbers.size(); i++)
    {
        plusDP[i + 1] = plusDP[i];
        for (int j = plus_numbers[i]; j < 50 * 50; j++)
        {
            plusDP[i + 1][j] += plusDP[i][j - plus_numbers[i]];
        }
    }
    for (int i = 0; i < minus_numbers.size(); i++)
    {
        minusDP[i + 1] = minusDP[i];
        for (int j = minus_numbers[i]; j < 50 * 50; j++)
        {
            minusDP[i + 1][j] += minusDP[i][j - minus_numbers[i]];
        }
    }
    ll ans = (1ll << zero_count) - 1ll;
    for (size_t i = 1; i < 50 * 50; i++)
    {
        ans += (1ll << zero_count) * plusDP.back()[i] * minusDP.back()[i];
    }
    cout << ans << endl;
    return 0;
}