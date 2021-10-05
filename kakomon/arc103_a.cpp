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
    map<ll, ll> odd_counts;
    map<ll, ll> even_counts;
    for (size_t i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        if (i % 2 == 0)
        {
            even_counts[a]++;
        }
        else
        {
            odd_counts[a]++;
        }
    }
    ll e_m1 = 0;
    ll e_m2 = 0;
    ll arg_e = -1;
    for (auto p : even_counts)
    {
        if (e_m1 < p.second)
        {
            e_m2 = e_m1;
            e_m1 = p.second;
            arg_e = p.first;
        }
        else if (e_m2 < p.second)
        {
            e_m2 = p.second;
        }
    }
    ll o_m1 = 0;
    ll o_m2 = 0;
    ll arg_o = -1;
    for (auto p : odd_counts)
    {
        if (o_m1 < p.second)
        {
            o_m2 = o_m1;
            o_m1 = p.second;
            arg_o = p.first;
        }
        else if (o_m2 < p.second)
        {
            o_m2 = p.second;
        }
    }
    if (arg_e == arg_o)
    {
        cout << min(N - o_m1 - e_m2, N - o_m2 - e_m1) << endl;
    }
    else
    {
        cout << N - o_m1 - e_m1 << endl;
    }

    return 0;
}