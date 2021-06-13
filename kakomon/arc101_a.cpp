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
    vector<ll> positive = {0};
    vector<ll> negative = {0};
    for (int i = 0; i < N; i++)
    {
        ll x;
        cin >> x;
        if (x < 0)
        {
            negative.push_back(-x);
        }
        else
        {
            positive.push_back(x);
        }
    }
    sort(negative.begin(), negative.end());
    ll min_moves = numeric_limits<ll>::max();
    for (size_t i = 0; i <= K; i++)
    {
        if (K-i < positive.size() && i < negative.size()){
            min_moves = min(min_moves, positive[K - i] + 2 * negative[i]);
        }
    }
    for (size_t i = 0; i <= K; i++)
    {
        if (K-i < positive.size() && i < negative.size()){
            min_moves = min(min_moves, 2 * positive[K - i] + negative[i]);
        }
    }
    cout << min_moves << endl;
    return 0;
}