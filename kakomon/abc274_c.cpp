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
    ll N;
    cin >> N;
    vector<ll> answers(2 * N + 2);
    for (ll i = 1; i <= N; i++)
    {
        ll a;
        cin >> a;
        answers[2 * i] = answers[a] + 1;
        answers[2 * i + 1] = answers[a] + 1;
    }
    for (ll i = 1; i <= 2 * N + 1; i++)
    {
        // if (i != 1)
        // {
        //     cout << " ";
        // }
        cout << answers[i] << "\n";
    }
    cout << flush;
    return 0;
}