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
    ll N;
    cin >> N;
    vector<pair<ll, ll>> Ts(N);
    for (int i = 0; i < N; i++)
    {
        string s, t;
        cin >> s >> t;
        Ts[i].first = stoll(s.substr(0, 2)) * 100 + stoll(s.substr(3));
        Ts[i].second = stoll(t.substr(0, 2)) * 100 + stoll(t.substr(3));
    }
    sort(Ts.begin(), Ts.end());
    vector<ll> DP(1ll << N, numeric_limits<ll>::max());
    DP[0] = 0;
    for (int i = 0; i < 1ll << N; i++)
    {
        ll others = ((1ll << N) - 1) ^ i;
        for (int sub = others; sub; sub = (sub - 1) & others)
        {
            bool is_ok = true;
            for (int j = 0; j < N; j++)
            {
                if (sub & 1ll << j)
                {
                    for (int k = j + 1; k < N; k++)
                    {
                        if (sub & 1ll << k)
                        {
                            if (Ts[k].first < Ts[j].second)
                            {
                                is_ok = false;
                            }
                            if (Ts[j].first < Ts[k].second - 2400)
                            {
                                is_ok = false;
                            }
                        }
                    }
                }
            }
            if (is_ok)
            {
                DP[i | sub] = min(DP[i | sub], DP[i] + 1);
            }
        }
    }
    cout << DP[(1ll<<N)-1] << endl;
    return 0;
}