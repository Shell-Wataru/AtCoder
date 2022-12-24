#define _USE_MATH_DEFINES
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
namespace mp = boost::multiprecision;

int main()
{
    ll N, W;
    cin >> N >> W;
    vector<ll> cumSum(200002, 0);
    for (int i = 0; i < N; i++)
    {
        ll s, t, p;
        cin >> s >> t >> p;
        cumSum[s] += p;
        cumSum[t] -= p;
    }
    for (int i = 0; i <= 200000; i++)
    {
        cumSum[i + 1] += cumSum[i];
    }
    for (int i = 0; i <= 200000; i++)
    {
        // cout << cumSum[i] << endl;
        if (cumSum[i] > W)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}