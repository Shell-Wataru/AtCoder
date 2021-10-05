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
    ll N;
    cin >> N;
    vector<ll> islands(N);
    ll total = 0;
    for (size_t i = 0; i < N; i++)
    {
        cin >> islands[i];
        total += islands[i];
    }
    if (total % N != 0)
    {
        cout << -1 << endl;
    }
    else
    {
        ll ans = 0;
        ll current_total = 0;
        ll per = total / N;
        ll lands = 0;
        for (ll i = 0; i < N; i++)
        {
            current_total += islands[i];
            lands++;
            if (current_total == per * lands)
            {
                current_total = 0;
                lands = 0;
            }else{
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}